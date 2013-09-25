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
  
  // Handle header image
  if (isset($vars['field_image'][0]['filepath'])) {
    if ($vars['field_image'][0]['data']['alt']) {
      $alt = $vars['field_image'][0]['data']['alt'];
    }
    else {
      $alt = $vars['node']->title;     
    }
    if ($vars['field_image'][0]['data']['title']) {
      $title = $vars['field_image'][0]['data']['title'];
    }
    else {
      $title = $vars['node']->title;     
    }
    $vars['head_image'] = theme('imagecache', 'headbrandimages', $vars['field_image'][0]['filepath'], $alt, $title );
  }
  
  // Handle media kit
  if (empty($vars['field_mediakit'][0]['value'])) { 
    $vars['mediakit'] = null;    
  }
  else { 
    $vars['mediakit'] = $vars['field_mediakit'][0]['value']; 
  }
  
  // Handle summary text in overview
  if (empty($vars['field_summary'][0]['value'])) { 
    $vars['summary'] = null;    
  }
  else { 
    $vars['summary'] = $vars['field_summary'][0]['value']; 
  }
  
  // Handle user defined Teaser text 
  if (empty($vars['field_website'][0]['url'])) { 
    $vars['website'] = null;    
  }
  else { 
    $vars['website']['url'] = $vars['field_website'][0]['url']; 
    $vars['website']['title'] = $vars['field_website'][0]['title']; 
  }
  
  // Set breadcrumbs for content of some brand
  if($vars['build_mode'] == 'brand_full'){
    $breadcrumb = drupal_get_breadcrumb();
    $breadcrumb[] = l('Brands','brands');
    drupal_set_breadcrumb($breadcrumb);
  }
}

