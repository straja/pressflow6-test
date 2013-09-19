<?php
/**
 * Preprocess variables for node-brands.tpl.php
 */
function diwanee_node_brands_preprocess(&$vars) {
  $vars['body'] = $vars['node']->content['body']['#value'];
  
  // Handle user defined Thumb image
  if (isset($vars['field_thumb'][0]['filepath'])) {
    if ($vars['field_thumb'][0]['data']['alt']) {
      $alt = $vars['field_thumb'][0]['data']['alt'];
    }
    else {
      $alt = $vars['node']->title;     
    }
    if ($vars['field_thumb'][0]['data']['title']) {
      $title = $vars['field_thumb'][0]['data']['title'];
    }
    else {
      $title = $vars['node']->title;     
    }
    $vars['thumb_image'] = theme('imagecache', 'brandimageteaser', $vars['field_thumb'][0]['filepath'], $alt, $title );
  }   
  
  // Handle user defined Teaser text 
  if (empty($vars['field_thumbtext'][0]['value'])) { 
    $vars['thumb_text'] = diwanee_corp_core_trim_text( $vars['node']->content['body']['#value'], 114, $chr = '…');    
  }
  else { 
    $vars['thumb_text'] = diwanee_corp_core_trim_text( $vars['field_thumbtext'][0]['value'], 144, $chr = '…'); 
  }
  
  // Handle logo for footer
  if (isset($vars['field_logo'][0]['filepath'])) {
    if ($vars['field_logo'][0]['data']['alt']) {
      $alt = $vars['field_logo'][0]['data']['alt'];
    }
    else {
      $alt = $vars['node']->title;     
    }
    if ($vars['field_logo'][0]['data']['title']) {
      $title = $vars['field_logo'][0]['data']['title'];
    }
    else {
      $title = $vars['node']->title;     
    }
    $vars['thumb_logo'] = theme('imagecache', 'brandlogos', $vars['field_logo'][0]['filepath'], $alt, $title );
  }
  
  // Set breadcrumbs for content of some brand
  if($vars['build_mode'] == 'brand_full'){
    $breadcrumb = drupal_get_breadcrumb();
    $breadcrumb[] = l('Brands','brands');
    drupal_set_breadcrumb($breadcrumb);
  }
}

