<?php
// $Id: views_handler_filter_watchdog_type.inc,v 1.1.4.1 2010/07/20 08:51:57 flanker Exp $

/**
 * @file
 * Views filter handler for the views_watchdog module.
 */


/**
 * Provides watchdog type filters.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_watchdog_type extends views_handler_filter_in_operator {


  function get_value_options() {

    if (!isset($this->value_options)) {

      $options = array();
      foreach (views_watchdog_get_type() as $key => $value) {
        $options[$value] = $value;
      }

      $this->value_options = $options;
    }
  }
}
