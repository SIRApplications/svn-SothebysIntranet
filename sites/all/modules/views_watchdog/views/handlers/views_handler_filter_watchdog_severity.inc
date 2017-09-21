<?php
// $Id: views_handler_filter_watchdog_severity.inc,v 1.1.2.1.2.2 2010/07/20 08:51:57 flanker Exp $

/**
 * @file
 * Views filter handler for the views_watchdog module.
 */


/**
 * Provides watchdog severity filters.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_watchdog_severity extends views_handler_filter_in_operator {


  function get_value_options() {

    if (!isset($this->value_options)) {

      $options = array();
      foreach (views_watchdog_get_severity() as $key => $value) {
        $options[$key] = $value['title'];
      }

      $this->value_options = $options;
    }
  }
}
