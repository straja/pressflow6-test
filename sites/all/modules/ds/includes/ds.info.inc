<?php

/**
 * @file
 * Info about a module.
 */

function ds_info($module) {
  $info = '';

  // API info about this module.
  $api_info = ds_api_info($module);
  $help = isset($api_info['help']) ? $api_info['help'] : array();

  // Let other modules add info.
  drupal_alter('ds_info', $help, $module);

  // General info (if any).
  if (!empty($help)) {
    $info = theme('item_list', $help);
  }

  if (!empty($info)) {
    return $info;
  }
  else {
    return t('No general info found.');
  }
}