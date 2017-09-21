<?php
// $Id: views_plugin_row_watchdog_rss.inc,v 1.1.2.1.2.2 2010/07/23 12:01:06 flanker Exp $

/**
 * @file
 * Views row plugin for the views_watchdog module.
 */


/**
 * Formats watchdog events as RSS items.
 *
 * @ingroup views_row_plugins
 */
class views_plugin_row_watchdog_rss extends views_plugin_row {


  function option_definition() {

    $options = parent::option_definition();

    $options['watchdog_rss_type'] = array('default' => 'default');
    $options['watchdog_rss_title'] = array('default' => '[severity] - [type]', 'translatable' => FALSE);

    return $options;
  }


  function options_form(&$form, &$form_state) {

    $form['watchdog_rss_type'] = array(
      '#type' => 'select',
      '#title' => t('Display type'),
      '#description' => t('The title includes the severity level and system event type.'),
      '#default_value' => $this->options['watchdog_rss_type'],
      '#options' => array(
        'fulltext' => t('Title plus message'),
        'title' => t('Title only'),
        'default' => t('Use default RSS settings'),
      ),
    );
    $form['watchdog_rss_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t('Alter the output of this field by specifying a string of text with replacement tokens. Replacement patterns: [type], [severity], [hostname]'),
      '#default_value' => $this->options['watchdog_rss_title'],
    );
  }


  function render($row) {

    $result = db_query('SELECT w.wid, w.type, w.message, w.variables, w.severity, w.hostname, w.timestamp, u.name FROM {watchdog} w LEFT JOIN {users} u ON w.uid = u.uid WHERE w.wid = %d', $row->wid);
    if ($watchdog = db_fetch_object($result)) {

      global $base_url;

      $tokens = array('[type]', '[severity]', '[hostname]');
      $values = array($watchdog->type, views_watchdog_get_severity($watchdog->severity, 'title'), $watchdog->hostname);

      $rss_type = $this->options['watchdog_rss_type'];
      if ($rss_type == 'default') {
        $rss_type = variable_get('feed_item_length', 'teaser');
      }

      $item = new stdClass();
      $item->title = str_replace($tokens, $values, check_plain($this->options['watchdog_rss_title']));
      $item->description = ($rss_type == 'fulltext' || $rss_type == 'teaser' ) ? views_watchdog_format_message($watchdog->message, $watchdog->variables) : '';
      $item->link = url('admin/reports/event/'. $watchdog->wid, array('absolute' => TRUE));
      $item->elements = array(
        array(
          'key' => 'pubDate',
          'value' => gmdate('r', $watchdog->timestamp),
        ),
        array(
          'key' => 'dc:creator',
          'value' => $watchdog->name,
        ),
        array(
          'key' => 'guid',
          'value' => 'log ' .  $watchdog->wid . ' at ' . $base_url,
          'attributes' => array('isPermaLink' => 'false'),
          'namespace' => array('xmlns:dc' => 'http://purl.org/dc/elements/1.1/'),
        ),
      );

      foreach ($item->elements as $element) {
        if (isset($element['namespace'])) {
          $this->view->style_plugin->namespaces = array_merge($this->view->style_plugin->namespaces, $element['namespace']);
        }
      }

      $output = theme($this->theme_functions(), $this->view, $this->options, $item);
    }
    else {

      $output = '';
    }

    return $output;
  }
}
