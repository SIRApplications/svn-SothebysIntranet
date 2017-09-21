<?php
// $Id: views_handler_field_watchdog_link.inc,v 1.1.2.1 2010/08/21 13:01:20 flanker Exp $

/**
 * @file
 * Views field handler for the views_watchdog module.
 */


/**
 * Provides display options of watchdog links.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_watchdog_link extends views_handler_field {


  function render($values) {

    return $values->{$this->field_alias};
  }
}
