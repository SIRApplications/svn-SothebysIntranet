<?php
// $Id: views_handler_field_watchdog_message.inc,v 1.1.2.2.2.2 2010/07/20 08:51:55 flanker Exp $

/**
 * @file
 * Views field handler for the views_watchdog module.
 */


/**
 * Provides display options of watchdog messages.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_watchdog_message extends views_handler_field {


  function init(&$view, &$data) {

    parent::init($view, $data);

    $this->additional_fields['variables'] = 'variables';
  }


  function option_definition() {

    $options = parent::option_definition();

    $options['watchdog_message_link'] = array('default' => TRUE);

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['watchdog_message_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link this field to its message'),
      '#description' => t('This will override any other link you have set.'),
      '#default_value' => $this->options['watchdog_message_link'],
    );
  }


  function render($values) {

    return $this->render_link(views_watchdog_format_message($values->watchdog_message, $values->{$this->aliases['variables']}), $values);
  }


  function render_link($data, $values) {

    if (!empty($this->options['watchdog_message_link']) && user_access('access site reports') && $values->wid && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'admin/reports/event/'. $values->wid;
    }

    return $data;
  }
}
