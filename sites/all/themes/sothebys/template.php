<?php
// $Id: template.php,v 0.1 2007/11/20 14:55:01 bself Exp $

/**
 * Declare the available regions implemented by this engine.
 *
 * Regions are areas in your theme where you can place blocks. The default
 * regions used in themes are "left sidebar", "right sidebar", "header", and
 * "footer", although you can create as many regions as you want. Once declared,
 * they are made available to the page.tpl.php file as a variable. For instance,
 * use <?php print $header ?> for the placement of the "header" region in
 * page.tpl.php.
 *
 * By going to the administer > site building > blocks page you can choose
 * which regions various blocks should be placed. New regions you define here
 * will automatically show up in the drop-down list by their human readable name.
 *
 * @return
 *   An array of regions. The first array element will be used as the default
 *   region for themes. Each array element takes the format:
 *   variable_name => t('human readable name')
 */
function sothebys_regions() {
  return array(
  	   'header_top' => t('header_top'),
  	   'header_bottom' => t('header_bottom'),
       'left_sidebar' => t('left sidebar'),
       'content_top' => t('content top'),
       'content_bottom' => t('content bottom'),
       'header' => t('header'),
       'header_links' => t('header links'),
       'footer' => t('footer')
  );
}

function phptemplate_menu_tree($pid = 1) {
  if ($tree = phptemplate_menu_tree_improved($pid)) {
    return "\n<ul class=\"menu\">\n". $tree ."\n</ul>\n";
  }
}

function phptemplate_menu_tree_improved($pid = 1) {
  $menu = menu_get_menu();
  $output = '';

  if (isset($menu['visible'][$pid]) && $menu['visible'][$pid]['children']) {
    $num_children = count($menu['visible'][$pid]['children']);
    for ($i=0; $i < $num_children; ++$i) {
      $mid = $menu['visible'][$pid]['children'][$i];
      $type = isset($menu['visible'][$mid]['type']) ? $menu['visible'][$mid]['type'] : NULL;
      $children = isset($menu['visible'][$mid]['children']) ? $menu['visible'][$mid]['children'] : NULL;
      $extraclass = $i == 0 ? 'first' : ($i == $num_children-1 ? 'last' : '');
      $output .= theme('menu_item', $mid, menu_in_active_trail($mid) || ($type & MENU_EXPANDED) ? theme('menu_tree', $mid) : '', count($children) == 0, $extraclass);     
    }
  }

  return $output;
}

function phptemplate_menu_item($mid, $children = '', $leaf = TRUE, $extraclass = '') {
  return '<li class="'. ($leaf ? 'leaf' : ($children ? 'expanded' : 'collapsed')) . ($extraclass ? ' ' . $extraclass : '') . '">'. menu_item_link($mid, TRUE, $extraclass) . $children ."</li>\n";
}

function phptemplate_search_theme_form($form) {
  /**
   * This snippet catches the default searchbox and looks for
   * search-theme-form.tpl.php file in the same folder
   * which has the new layout.
   */
  return theme_render_template('search-theme-form', array('form' => $form));
}

 /**
  * Return a themed breadcrumb trail.
  *
  * @param $breadcrumb
  *   An array containing the breadcrumb links.
  * @return
  *   A string containing the breadcrumb output.
  */
 function sothebys_breadcrumb($breadcrumb) {
   if (!empty($breadcrumb)) {
     return '<div class="breadcrumb">'. implode(' // ', $breadcrumb) . ' // ' . drupal_get_title() . '</div>';
   }
 }


/**
 * Intercept template variables
 *
 * @param $hook
 *   The name of the theme function being executed
 * @param $vars
 *   A sequential array of variables passed to the theme function.
 */

function _phptemplate_variables($hook, $vars = array()) {
      global $user;
      $vars['user'] = $user->name;

  $vars['section'] = taxonomy_node_get_terms($node);
  
  switch ($hook) {
    case 'page':
      $vars['body_class'] = '';

      // Set body class for formatting based on content type
      // if the node exists, i.e., if a node is the focus of the page.
      $vars['body_class'] = isset($vars['node']) ? 'type_' . $vars['node']->type .' ' : '';

      if (drupal_is_front_page()) {
         $vars['body_class'] .= ' home';
      }

      break;
  }
  
  
  return $vars;
} 

/*
 * This section integrates with the modified 'Attachments' module
 * and the 'Relativity' module
 * If those modules are not installed, we don't want this function
 */
if (module_exists('attachment_ext') && module_exists('relative')) {
function sothebys_relative_show_children($parent, $fieldset=1) {
  $output = '';
	
  // load all nodes associated with this one as the parent nid and show links to all of them.
  $result = db_query('SELECT nid FROM {relative} WHERE parent_nid = %d', $parent->nid);
  while($child = db_fetch_object($result)) {
    $child_nodes[] = node_load($child->nid);
  }
  if (!is_array($child_nodes)) return '';

  $childrentypes = relative_childrentypes($parent); // sorted list of types

  foreach($childrentypes as $childtype) {
    $child_display_option = variable_get('relative_render_'. $parent->type .'_'. $childtype, 'title');
    if (strpos($child_display_option, 'view:') !== FALSE) {
      $viewname = str_replace('view:', '', $child_display_option);
      $children_box = relative_child_as_view($parent, $childtype, $viewname);
    } else {
      $children_box = "\n";
      foreach($child_nodes as $child_node) {
        if ($child_node->type != $childtype) continue;
        switch ($child_display_option) {
          case 'title':
            if ((node_access("view", $child_node)) && (($child_node->type == 'ef') || ($child_node->type == 'wf') || ($child_node->type == 'mf') || ($child_node->type == 'sf'))) {
	            $timespan = variable_get('attachments_ext_timespan', 2592000);
		        if ($child_node -> changed > (time() - $timespan)) {
		        	if ($child_node->changed != $child_node->created) {
	    	    		$newText = "Revised";
	        		} else {
	        			$newText = "New";
	        		}
		        }
              $children_box .= '<span class="new">' . $newText . ' </span>';
              $children_box .= l(t($child_node->title), 'node/'.$child_node->nid, array('class' => 'relative_view_' . $childtype)) . "<br />\n";
              $output .= ($children_box ? "\n" . '<div class="relative_child">' . $children_box . "</div>\n" : '');
            }
            
            break;
          case 'teaser':
            $children_box .= theme('fieldset', array('#title' => node_get_types('name', $childtype), 
                                                     '#children' => node_view($child_node, TRUE)));
            $output .= ($children_box ? "\n" . '<div class="relative_child">' . $children_box . "</div>\n" : '');
            break;
          case 'body':
            $children_box .= theme('fieldset', array('#title' => node_get_types('name', $childtype), 
                                                     '#children' => node_view($child_node, FALSE)));
            $output .= ($children_box ? "\n" . '<div class="relative_child">' . $children_box . "</div>\n" : '');
            break;
        }
      }
    }  
//    $output .= ($children_box ? "\n" . '<div class="relative_child">' . $children_box . "</div>\n" : '');
  }

  if ($output && $fieldset) {
    $output = "\n" . theme('fieldset', array('#title' => variable_get('relative_children_label', t('&nbsp;')), 
                                      '#children' => $output));
  }
  return $output;
}
}

function sothebys_links($links, $attributes = array('class' => 'links')) {
  $output = '';

  if (count($links) > 0) {

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = '';

      // Automatically add a class to each link and also to each LI
      if (isset($link['attributes']) && isset($link['attributes']['class'])) {
        $link['attributes']['class'] .= ' ' . $key;
        $class = $key;
      }
      else {
        $link['attributes']['class'] = $key;
        $class = $key;
      }

      // Add first and last classes to the list of links to help out themers.
      $extra_class = '';
      if ($i == 1) {
        $extra_class .= 'first ';
      }
      if ($i == $num_links) {
        $extra_class .= 'last ';
      }

      // Is the title HTML?
      $html = isset($link['html']) && $link['html'];

      // Initialize fragment and query variables.
      $link['query'] = isset($link['query']) ? $link['query'] : NULL;
      $link['fragment'] = isset($link['fragment']) ? $link['fragment'] : NULL;

      if (isset($link['href'])) {
        $output .= l($link['title'], $link['href'], $link['attributes'], $link['query'], $link['fragment'], FALSE, $html);
      }
      else if ($link['title']) {
        //Some links are actually not links, but we wrap these in <span> for adding title and class attributes
        if (!$html) {
          $link['title'] = check_plain($link['title']);
        }
        $output .= '<span'. drupal_attributes($link['attributes']) .'>'. $link['title'] .'</span>';
      }
	  if ($i != $num_links)
	  	$output .= "&nbsp;&nbsp;|&nbsp;&nbsp;";
      $i++;
    }
  }

  return $output;
}

?>
