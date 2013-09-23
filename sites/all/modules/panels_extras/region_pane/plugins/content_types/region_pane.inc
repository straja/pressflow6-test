<?php
// $Id: region_pane.inc,v 1.0 2011/03/17 16:50:48  chriscalip Exp $

/**
 * @file
 * Plugin to handle the 'region_pane' content type which allows the contents
 * of a drupal regions to be included in a panel
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Region Based Pane'),
  'single' => TRUE,
  'content_types' => 'region_pane_content_type',
  'render callback' => 'region_pane_content_type_render',
  'edit form' => 'region_pane_content_type_edit_form',
  'description' => t('Get the content of an entire region'),
  'category' => t('Panels Extras'),
);

/**
 * Output function for the 'region_pane' content type.
 *
 * Outputs the breadcrumb for the current page.
 * @param unknown_type $subtype
 * @param unknown_type $conf
 * @param unknown_type $panel_args
 * @return object $block
 */
function region_pane_content_type_render($subtype, $conf, $panel_args) {
  // Optionally get rid of the homepage link.
  $region = $conf['config_item_region_pane_selected_region'];
  $region_content = theme_blocks($region);
  $block = new stdClass();
  $block->content = $region_content;
  return $block;
}


/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function region_pane_content_type_edit_form(&$form, &$form_state) {
  $settings = $form_state['conf'];
  $themes_list = list_themes();
  $regions_list = array();
  foreach ($themes_list as $theme) {
    $regions_list = array_merge($regions_list, system_region_list($theme->name));
  }
  $form['config_item_region_pane_selected_region'] = array(
    '#type'          => 'select',
    '#default_value' => $settings['config_item_region_pane_selected_region'],
    '#title'         => t('Region List'),
    '#options'       => $regions_list,  
  );
  return $form;
}

function region_pane_content_type_edit_form_submit(&$form, &$form_state) {
  foreach ( element_children($form) as $key ) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}