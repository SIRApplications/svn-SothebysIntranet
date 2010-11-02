<?php
// $Id: relative_views.inc,v 1.4 2007/04/04 19:51:53 darius Exp $

function relative_views_tables() {
  $tables['relative'] = array(
    'name' => 'relative',
    'provider' => 'internal',
    'join' => array('left' => array('table' => 'node',
                                    'field' => 'nid'),
                    'right' => array('field' => 'nid')),
    'filters' => array('parent_nid' => array('name' => t('Relativity: Parent Node'),
                                             'list' => 'views_handler_filter_relative_parent_zero',
                                             'operator' => 'views_handler_operator_andor',
                                             'help' => t('This allows you to filter nodes based on parent node ID and title.')),
    ),
  );

  $tables['relative_parent_node'] = array(
    'name' => 'node',
    'provider' => 'internal',
    'join' => array(
      'left' => array(
        'table' => 'relative',
        'field' => 'parent_nid'
      ),
      'right' => array(
        'field' => 'nid'
      )
    ),
    'fields' => array(
      'title' => array(
        'name' => t('Relativity: Parent Title'),
        'handler' => array(
          'views_handler_field_relative_parent_title'    => t('As Link'),
          'views_handler_field_relative_parent_title_nl' => t('Without Link'),
        ),
        'sortable' => TRUE,
        'addlfields' => array('nid'),
        'help' => t('Display the title of the parent node'),
      ),
    ),
    'sorts' => array(
      'title' => array(
        'name' => t('Relativity: Parent Title'),
        'help' => t('Sort by the title of the parent node'),
      ),
    ),
  );

  return $tables;
}

function relative_views_arguments() {
  $arguments = array(
    'relative_parent' => array(
      'name' => t("Relativity: Parent Node ID"),
      'handler' => "views_handler_arg_relative_parent",
    ),
  );
  return $arguments;
}

function relative_views_default_views() {

}

function views_handler_arg_relative_parent($op, & $query, $argtype, $arg = '') {
  switch ($op)
  {
    case 'summary' :
      $query->ensure_table("relative_parent_node");
      $query->add_field("nid");
      $query->add_field("parent_nid", "relative");
      $query->add_field("title", "relative_parent_node");
      $query->add_field("nid", "relative_parent_node", "pnid");
      $query->add_where("relative_parent_node.nid IS NOT NULL");
      $fieldinfo['field'] = "relative_parent_node.title";
      return $fieldinfo;
      break;
    case 'sort':
      $query->add_orderby('relative_parent_node', 'title', $argtype);
      break;
    case 'filter' :
      $query->ensure_table("relative");
      $query->add_where("relative.parent_nid = %d", $arg);
      break;
    case 'link' :
      return l($query->title, "$arg/$query->pnid");
    case 'title' :
      if ($query)
      {
        $term = db_fetch_object(db_query("SELECT title FROM {node} WHERE nid = '%d'", $query));
        return $term->title;
      }
  }
}

/*
 * Format a field as a link to the parent node
 */
function views_handler_field_relative_parent_title($fieldinfo, $fielddata, $value, $data) {
  return l($value, "node/$data->relative_parent_node_nid");
}

function views_handler_field_relative_parent_title_nl($fieldinfo, $fielddata, $value, $data) {
  return check_plain($value);
}

function views_handler_filter_relative_parent_zero() {
  $parents = array();
  $result = db_query("SELECT DISTINCT parent_nid FROM {relative} ORDER BY parent_nid");
  while ($obj = db_fetch_object($result)) {
    $node = node_load($obj->parent_nid);
    $parents[$obj->parent_nid] = "$obj->parent_nid. $node->title";
  }
  return $parents;
}