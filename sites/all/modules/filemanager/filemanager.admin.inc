<?php
/**
 * Displays filemanager admin screen
 */
function filemanager_admin_settings() {
  global $base_url;

  $public_directory_path = variable_get('filemanager_public_path', 'files');
  
  $form['filemanager_public_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Public file system path'),
    '#default_value' => $public_directory_path,
    '#maxlength' => 255,
    '#after_build' => array('_filemanager_settings_check_directory'),
    '#description' => t('A file system path where public files will be stored. This directory has to exist and be writable by Drupal. This directory has to be accessible over the web. Changing this location after the site has been in use will cause problems so only change this setting on an existing site if you know what you are doing.')
  );
  $form['filemanager_public_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Public file system URL'),
    '#default_value' => variable_get('filemanager_public_url', $base_url .'/'. $public_directory_path),
    '#maxlength' => 255,
    '#description' => t('Base URL that points to the public files directory.')
  );
  $form['filemanager_private_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Private file system path'),
    '#default_value' => variable_get('filemanager_private_path', 'private'),
    '#maxlength' => 255,
    '#after_build' => array('_filemanager_settings_check_directory'),
    '#description' => t('A file system path where private access controlled files will be stored. This directory has to exist and be writable by Drupal. This directory should not be accessible over the web. Changing this location after the site has been in use will cause problems so only change this setting on an existing site if you know what you are doing.')
  );
  $form['filemanager_max_filecount'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum files per directory'),
    '#default_value' => variable_get('filemanager_max_filecount', '200'),
    '#size' => 6,
    '#maxlength' => 10,
    '#description' => t('Maximum number of files to put in each directory.'));
  $form['filemanager_working_sizelimit'] = array(
    '#type' => 'textfield',
    '#title' => t('Working size limit'),
    '#default_value' => variable_get('filemanager_working_sizelimit', '10'),
    '#size' => 6,
    '#maxlength' => 10,
    '#description' => t('Maximum total size in megabytes for the working storage directory. Enter -1 for unlimited.'),
    '#requred' => true
  );
  $form['filemanager_working_maxage'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum working age'),
    '#default_value' => variable_get('filemanager_working_maxage', '120'),
    '#size' => 6,
    '#maxlength' => 10,
    '#description' => t('Maximum amoung of time in minutes that an attachment is allowed to live in working storage. Enter -1 for unlimited.'),
    '#requred' => true
  );
  $form['filemanager_max_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum size limit'),
    '#default_value' => variable_get('filemanager_max_size', '400'),
    '#size' => 6,
    '#maxlength' => 10,
    '#description' => t('Maximum amount of disk space that can be consumed by all files. Enter in megabytes.'),
    '#requred' => true
  );

  $form['file_areas'] = array(
    '#type' => 'fieldset',
    '#title' => t('File areas'),
    '#tree' => true,
    '#theme' => 'filemanager_fileareas_admin',
    'info' => array(
      '#type' => 'markup',
      '#value' => '<em>'. t("The following numbers control the total size of all files allowed in a particular area. Enter '-1' to allow unlimited size. Select force private to force all files in that area to be streamed (no direct access) through the private directory.  If the module that controls that area does not enforce security it will default to allow all access.") .'</em>'
    ),
  );
  foreach(filemanager_area_list() as $area) {
    $key = $area['area'];
    $form['file_areas']['areas'][$key] = array(
      '#description' => $area['description'],
      '#title' => $area['name'],
      'limit' => array(
        'filemanager_area_limit_' . $key => array(
          '#type' => 'textfield',
          '#default_value' => variable_get('filemanager_area_limit_' . $key, '-1'),
          '#size' => 6,
          '#maxlength' => 10,
        ),
      ),
      'force' => array(
        'filemanager_force_private_' . $key => array(
          '#type' => 'checkbox',
          '#default_value' => variable_get('filemanager_force_private_' . $key, 0),
          '#return_value' => 1,
        ),
      ),
    );
  }

  return system_settings_form($form);
}

function theme_filemanager_fileareas_admin($form) {
  $output = drupal_render($form['info']);

  $header = array(t('Area'),t('Description'),t('Max size (Mb)'),t('Force Private'));
  foreach (element_children($form['areas']) as $key) {
    $row = array();
    $row[] = $form['areas'][$key]['#title'];
    $row[] = $form['areas'][$key]['#description'];
    $row[] = drupal_render($form['areas'][$key]['limit']);
    $row[] = drupal_render($form['areas'][$key]['force']);
    $rows[] = $row;
  }
  $output .= theme('table', $header, $rows);

  $output .= drupal_render($form);
  return $output;
}

/**
 * Handle the submission of the admin/settings form. This is a bit unusual
 * since the settings form is normally handled automatically, but due to the
 * deep fileareas->areas array used for the file areas table, the
 * system_settings_form_submit can't handle all the values without some
 * pre-processing.
 */
function filemanager_admin_settings_submit($form, &$form_state) {
  // Flatten the fileareas array into $values
  foreach ($values['file_areas']['areas'] as $area => $settings) {
    foreach ($settings as $value_key => $value_array) {
      foreach ($value_array as $key => $value) {
        $values[$key] = $value;
      }
    }
  }
  system_settings_form_submit($form_state['values']['form_id'], $values);
}
?>
