<?php
// $Id: views_handler_field_watchdog_severity.inc,v 1.1.2.3.2.2 2010/07/20 08:51:55 flanker Exp $

/**
 * @file
 * Views field handler for the views_watchdog module.
 */


/**
 * Provides display options of watchdog severity.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_watchdog_severity extends views_handler_field {


  function option_definition() {

    $options = parent::option_definition();

    $options['watchdog_severity_icon'] = array('default' => TRUE);
    foreach (views_watchdog_get_severity() as $key => $value) {
      $options['watchdog_severity_icon_'. $value['arg']] = array('default' => $value['icon'], 'translatable' => FALSE);
    }

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['watchdog_severity_icon'] = array(
      '#title' => t('Display severity level as icon'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['watchdog_severity_icon']),
    );
    foreach (views_watchdog_get_severity() as $key => $value) {
      $form['watchdog_severity_icon_'. $value['arg']] = array(
        '#type' => 'textfield',
        '#title' => $value['title'],
        '#description' => t('The path to the image file you would like to use as icon.'),
        '#default_value' => $this->options['watchdog_severity_icon_'. $value['arg']],
        '#process' => array('views_process_dependency'),
        '#dependency' => array(
          'edit-options-watchdog-severity-icon' => array(1),
        ),
      );
    }
  }


  function options_validate(&$form, &$form_state) {

    parent::options_validate($form, $form_state);

    foreach (views_watchdog_get_severity() as $key => $value) {
      $path = trim($form_state['values']['options']['watchdog_severity_icon_'. $value['arg']]);
      $field = $form['watchdog_severity_icon_'. $value['arg']];
      if (!empty($path) && !is_file($path)) {
        form_error($field, t("File doesn't exist."));
      }
    }
  }


  function render($values) {

    if ($this->options['watchdog_severity_icon']) {
      $arg = views_watchdog_get_severity($values->watchdog_severity, 'arg');
      $output = views_watchdog_get_severity_icon($values->watchdog_severity, $this->options['watchdog_severity_icon_'. $arg]);
    }
    else {
      $output = views_watchdog_get_severity($values->watchdog_severity, 'title');
    }

    return $output;
  }
}
