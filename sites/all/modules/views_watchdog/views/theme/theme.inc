<?php
// $Id: theme.inc,v 1.1.2.2.2.3 2010/07/20 10:10:58 flanker Exp $

/**
 * @file
 * Template preprocessors for the views_watchdog module.
 */


/**
 * Display a view as a watchdog table style.
 */
function template_preprocess_views_view_watchdog_table(&$vars) {
  $view     = $vars['view'];

  // We need the raw data for this grouping, which is passed in as $vars['rows'].
  // However, the template also needs to use for the rendered fields.  We
  // therefore swap the raw data out to a new variable and reset $vars['rows']
  // so that it can get rebuilt.
  // Store rows so that they may be used by further preprocess functions.
  $result   = $vars['result'] = $vars['rows'];
  $vars['rows'] = array();

  $options  = $view->style_plugin->options;
  $handler  = $view->style_plugin;

  $fields   = &$view->field;
  $columns  = $handler->sanitize_columns($options['columns'], $fields);

  $active   = !empty($handler->active) ? $handler->active : '';
  $order    = !empty($handler->order) ? $handler->order : 'asc';

  $query    = tablesort_get_querystring();
  if ($query) {
    $query = '&' . $query;
  }

  // Fields must be rendered in order as of Views 2.3, so we will pre-render
  // everything.
  $renders = $handler->render_fields($result);

  foreach ($columns as $field => $column) {
    // render the header labels
    if ($field == $column && empty($fields[$field]->options['exclude'])) {
      $label = check_plain(!empty($fields[$field]) ? $fields[$field]->label() : '');
      if (empty($options['info'][$field]['sortable']) || !$fields[$field]->click_sortable()) {
        $vars['header'][$field] = $label;
      }
      else {
        // @todo -- make this a setting
        $initial = 'asc';

        if ($active == $field && $order == 'asc') {
          $initial = 'desc';
        }

        $title = t('sort by @s', array('@s' => $label));
        if ($active == $field) {
          $label .= theme('tablesort_indicator', $initial);
        }
        $link_options = array(
          'html' => true,
          'attributes' => array('title' => $title),
          'query' => 'order=' . urlencode($field) . '&sort=' . $initial . $query,
        );
        $vars['header'][$field] = l($label, $_GET['q'], $link_options);
      }
    }

    // Create a second variable so we can easily find what fields we have and what the
    // CSS classes should be.
    $vars['fields'][$field] = views_css_safe($field);
    if ($active == $field) {
      $vars['fields'][$field] .= ' active';
    }

    // Render each field into its appropriate column.
    foreach ($result as $num => $row) {
      if (!empty($fields[$field]) && empty($fields[$field]->options['exclude'])) {
        $field_output = $renders[$num][$field];

        if (!isset($vars['rows'][$num][$column])) {
          $vars['rows'][$num][$column] = '';
        }

        // Don't bother with separators and stuff if the field does not show up.
        if ($field_output === '') {
          continue;
        }

        // Place the field into the column, along with an optional separator.
        if ($vars['rows'][$num][$column] !== '') {
          if (!empty($options['info'][$column]['separator'])) {
            $vars['rows'][$num][$column] .= filter_xss_admin($options['info'][$column]['separator']);
          }
        }

        $vars['rows'][$num][$column] .= $field_output;
      }
    }
  }

  $count = 0;
  foreach ($vars['rows'] as $num => $row) {
    $vars['row_classes'][$num][] = ($count++ % 2 == 0) ? 'odd' : 'even';
  }

  // Add custom CSS classes.
  if (isset($vars['view']->style_plugin->options['watchdog_table_severity'])) {
    if ($vars['view']->style_plugin->options['watchdog_table_severity']) {
      foreach ($vars['view']->result as $key => $value) {
        $code = db_result(db_query('SELECT severity FROM {watchdog} WHERE wid = %d', $value->wid));
        $arg = views_watchdog_get_severity($code, 'arg');
        $class = trim($vars['view']->style_plugin->options['watchdog_table_severity_'. $arg]);
        if (!empty($class)) {
          $vars['row_classes'][$key][] = check_plain($class);
        }
      }
    }
  }

  $vars['row_classes'][0][] = 'views-row-first';
  $vars['row_classes'][count($vars['row_classes']) - 1][] = 'views-row-last';

  $vars['class'] = 'views-watchdog-table';
  if (!empty($options['sticky'])) {
    drupal_add_js('misc/tableheader.js');
    $vars['class'] .= " sticky-enabled";
  }
  $vars['class'] .= ' cols-'. count($vars['rows']);
}
