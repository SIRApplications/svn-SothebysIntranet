<?php
// $Id: sothebys_front_page.inc,v 1.5.6.8 2008/07/18 22:53:51 sdboyer Exp $

/**
 * implementation of hook_panels_layouts
 */
function sothebys_front_page_panels_layouts() {
  $items['sothebys_front_page'] = array(
    'title' => t('Sothebys front page layout'),
    'icon' => 'layouts/threecol_25_50_25_stacked.png',
    'theme' => 'sothebys_front_page',
    'css' => 'layouts/threecol_25_50_25_stacked.css',
    'panels' => array(
      'top_left' => t('Top Left'),
      'top_middle' => t('Top middle'),
      'top_right' => t('Top right'),
      'bar' => t('Horizontal Bar'),
      'bottom_column_one' => t('Bottom column one'),
      'bottom_column_two' => t('Bottom column two'),
      'bottom_column_three' => t('Bottom column three'),
      'bottom_column_four' => t('Bottom column four')
    ),
  );

  return $items;
}

/**
 * This function uses heredoc notation to make it easier to convert
 * to a template.
 */
function theme_sothebys_front_page($id, $content) {
  if ($id) {
    $idstr = " id='$id'";
  }

  $output = <<<EOT
<div class="panel-display panel-3col-stacked clear-block" $idstr>
  <div class="center-wrapper">
    <div class="panel-panel panel-col-first">
      <div class="inside">$content[top_left]</div>
    </div>

    <div class="panel-panel panel-col">
      <div class="inside">$content[top_middle]</div>
    </div>

    <div class="panel-panel panel-col-last">
      <div class="inside">$content[right]</div>
    </div>
  </div>
  <div class="panel-panel panel-col-bottom">
    <div class="inside">$content[bottom]</div>
  </div>
</div>
EOT;
  return $output;
}

