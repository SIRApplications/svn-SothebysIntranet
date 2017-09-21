<?php
// $Id: views_watchdog.views_default.inc,v 1.1.2.3 2010/09/07 17:06:12 flanker Exp $

/**
 * @file
 * Default views for the views_watchdog module.
 */


/**
 * Implementation of hook_views_default_views().
 */
function views_watchdog_views_default_views() {

  $view = new view;
  $view->name = 'watchdog';
  $view->description = 'Watchdog entries';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'watchdog';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'uid' => array(
      'label' => 'uid',
      'required' => 0,
      'id' => 'uid',
      'table' => 'watchdog',
      'field' => 'uid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'severity' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'watchdog_severity_icon' => 1,
      'watchdog_severity_icon_emerg' => 'misc/watchdog-error.png',
      'watchdog_severity_icon_alert' => 'misc/watchdog-error.png',
      'watchdog_severity_icon_critical' => 'misc/watchdog-error.png',
      'watchdog_severity_icon_error' => 'misc/watchdog-error.png',
      'watchdog_severity_icon_warning' => 'misc/watchdog-warning.png',
      'watchdog_severity_icon_notice' => '',
      'watchdog_severity_icon_info' => '',
      'watchdog_severity_icon_debug' => '',
      'exclude' => 0,
      'id' => 'severity',
      'table' => 'watchdog',
      'field' => 'severity',
      'relationship' => 'none',
    ),
    'type' => array(
      'label' => 'Type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'type',
      'table' => 'watchdog',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => 'Date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'watchdog',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'message' => array(
      'label' => 'Message',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '50',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'watchdog_message_link' => 1,
      'exclude' => 0,
      'id' => 'message',
      'table' => 'watchdog',
      'field' => 'message',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'uid',
    ),
    'link' => array(
      'label' => 'Operations',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'link',
      'table' => 'watchdog',
      'field' => 'link',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'id' => 'timestamp',
      'table' => 'watchdog',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'wid' => array(
      'order' => 'DESC',
      'id' => 'wid',
      'table' => 'watchdog',
      'field' => 'wid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'type_op',
        'identifier' => 'type',
        'label' => 'Type',
        'optional' => 1,
        'single' => 0,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'type',
      'table' => 'watchdog',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'severity' => array(
      'operator' => 'in',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'severity_op',
        'identifier' => 'severity',
        'label' => 'Severity',
        'optional' => 1,
        'single' => 0,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'severity',
      'table' => 'watchdog',
      'field' => 'severity',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'access site reports',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Watchdog entries');
  $handler->override_option('header', 'Watchdog entries are a list of recorded system events.');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'watchdog_table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 0,
    'sticky' => 1,
    'order' => 'desc',
    'columns' => array(
      'severity' => 'severity',
      'type' => 'type',
      'timestamp' => 'timestamp',
      'message' => 'message',
      'name' => 'name',
    ),
    'info' => array(
      'severity' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'timestamp' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'message' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => 'timestamp',
    'watchdog_table_severity' => 1,
    'watchdog_table_severity_emerg' => 'dblog-emerg',
    'watchdog_table_severity_alert' => 'dblog-alert',
    'watchdog_table_severity_critical' => 'dblog-critical',
    'watchdog_table_severity_error' => 'dblog-error',
    'watchdog_table_severity_warning' => 'dblog-warning',
    'watchdog_table_severity_notice' => 'dblog-notice',
    'watchdog_table_severity_info' => 'dblog-info',
    'watchdog_table_severity_debug' => 'dblog-debug',
  ));

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'admin/reports/watchdog');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Watchdog entries',
    'description' => 'View system events that have been logged.',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('fields', array(
    'severity' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'watchdog_severity_icon' => 1,
      'watchdog_severity_icon_emerg' => 'misc/watchdog-error.png',
      'watchdog_severity_icon_alert' => 'misc/watchdog-error.png',
      'watchdog_severity_icon_critical' => 'misc/watchdog-error.png',
      'watchdog_severity_icon_error' => 'misc/watchdog-error.png',
      'watchdog_severity_icon_warning' => 'misc/watchdog-warning.png',
      'watchdog_severity_icon_notice' => '',
      'watchdog_severity_icon_info' => '',
      'watchdog_severity_icon_debug' => '',
      'exclude' => 0,
      'id' => 'severity',
      'table' => 'watchdog',
      'field' => 'severity',
      'relationship' => 'none',
    ),
    'type' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'type',
      'table' => 'watchdog',
      'field' => 'type',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'message' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '20',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'watchdog_message_link' => 1,
      'exclude' => 0,
      'id' => 'message',
      'table' => 'watchdog',
      'field' => 'message',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('title', 'Recent log entries');
  $handler->override_option('header', '');
  $handler->override_option('header_empty', 0);
  $handler->override_option('items_per_page', 10);
  $handler->override_option('use_pager', '0');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 1);
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 0,
    'sticky' => 0,
    'order' => 'desc',
    'columns' => array(
      'severity' => 'severity',
      'type' => 'type',
      'message' => 'message',
    ),
    'info' => array(
      'severity' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'type' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'message' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
    'watchdog_table_severity' => 1,
    'watchdog_table_severity_emerg' => 'dblog-emerg',
    'watchdog_table_severity_alert' => 'dblog-alert',
    'watchdog_table_severity_critical' => 'dblog-critical',
    'watchdog_table_severity_error' => 'dblog-error',
    'watchdog_table_severity_warning' => 'dblog-warning',
    'watchdog_table_severity_notice' => 'dblog-notice',
    'watchdog_table_severity_info' => 'dblog-info',
    'watchdog_table_severity_debug' => 'dblog-debug',
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->override_option('header', '');
  $handler->override_option('header_empty', 0);
  $handler->override_option('items_per_page', 10);
  $handler->override_option('style_plugin', 'rss');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('row_plugin', 'watchdog_rss');
  $handler->override_option('path', 'admin/reports/watchdog/feed');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
    'block_1' => 0,
  ));
  $handler->override_option('sitename_title', FALSE);

  $views = array();
  $views[$view->name] = $view;

  return $views;
}
