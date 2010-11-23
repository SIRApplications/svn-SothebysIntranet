<?php
// $Id: template.php,v 0.1 2007/11/20 14:55:01 bself Exp $



function sothebys_v6_preprocess_search_theme_form(&$vars, $hook) {
  // Remove the "Search this site" label from the form.
  $vars['form']['search_theme_form']['#title'] = t('Search');
 
  // Set a default value for text inside the search box field.
  $vars['form']['search_theme_form']['#value'] = t('');
 
  // Add a custom class and placeholder text to the search box.
  $vars['form']['search_theme_form']['#attributes'] = array('class' => 'NormalTextBox txtSearch',
                                                              'onfocus' => "if (this.value == 'Search this Site') {this.value = '';}",
                                                              'onblur' => "if (this.value == '') {this.value = 'Search this Site';}");
 
  // Change the text on the submit button
  //$vars['form']['submit']['#value'] = t('Go');

  // Rebuild the rendered version (search form only, rest remains unchanged)
  unset($vars['form']['search_theme_form']['#printed']);
  $vars['search']['search_theme_form'] = drupal_render($vars['form']['search_theme_form']);

  $vars['form']['submit']['#type'] = 'image_button';
  $vars['form']['submit']['#src'] = 'files/icon-search.png';
   
  // Rebuild the rendered version (submit button, rest remains unchanged)
  unset($vars['form']['submit']['#printed']);
  $vars['search']['submit'] = drupal_render($vars['form']['submit']);

  // Collect all form elements to make it easier to print the whole form.
  $vars['search_form'] = implode($vars['search']);
}

 /**
  * Return a themed breadcrumb trail.
  *
  * @param $breadcrumb
  *   An array containing the breadcrumb links.
  * @return
  *   A string containing the breadcrumb output.
  */
 function sothebys_v6_breadcrumb($breadcrumb) {
   if (!empty($breadcrumb)) {
   		return implode(' // ', $breadcrumb);
   }
   
 }
 
 function menu_get_active_trail_stuff() {
 	$trail = "";
 	$tmp = "";
 	$ary = menu_get_active_trail();
 	foreach($ary as $value) {
 		$tmp = str_replace('&', '', str_replace(' ', '', $value['title'])) . " "; 		
 		$trail = $tmp;
 		
 		if($tmp != "Home "){
 			break;
 		} 		
 	}
 	return $trail;
 }
 