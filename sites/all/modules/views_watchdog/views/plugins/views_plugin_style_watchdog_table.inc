<?php
// $Id: views_plugin_style_watchdog_table.inc,v 1.1.2.2.2.1 2010/07/20 09:52:49 flanker Exp $

/**
 * @file
 * Views style plugin for the views_watchdog module.
 */


/**
 * Provides style options for watchdog tables.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_watchdog_table extends views_plugin_style_table {


  function option_definition() {

    $options = parent::option_definition();

    $options['watchdog_table_severity'] = array('default' => TRUE);
    foreach (views_watchdog_get_severity() as $key => $value) {
      $options['watchdog_table_severity_'. $value['arg']] = array('default' => $value['class'], 'translatable' => FALSE);
    }

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['watchdog_table_severity'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add CSS classes to each table row based on severity level.'),
      '#default_value' => !empty($this->options['watchdog_table_severity']),
    );
    foreach (views_watchdog_get_severity() as $key => $value) {
      $form['watchdog_table_severity_'. $value['arg']] = array(
        '#type' => 'textfield',
        '#title' => $value['title'],
        '#description' => $value['text'],
        '#default_value' => $this->options['watchdog_table_severity_'. $value['arg']],
        '#process' => array('views_process_dependency'),
        '#dependency' => array(
          'edit-style-options-watchdog-table-severity' => array(1),
        ),
      );
    }
  }


  function options_validate(&$form, &$form_state) {

    parent::options_validate($form, $form_state);

    foreach (views_watchdog_get_severity() as $key => $value) {
      $class = trim($form_state['values']['style_options']['watchdog_table_severity_'. $value['arg']]);
      $field = $form['watchdog_table_severity_'. $value['arg']];
      if (preg_match('/[^a-zA-Z0-9-]/', $class)) {
        form_error($field, t('CSS class name must be alphanumeric or dashes only.'));
      }
    }
  }
}
