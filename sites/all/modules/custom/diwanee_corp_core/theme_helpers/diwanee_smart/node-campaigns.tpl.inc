<?php
/**
 * Preprocess variables for node-campaigns.tpl.php
 */
function diwanee_smart_node_campaigns_preprocess(&$vars) {

  $vars['body'] = $vars['node']->content['body']['#value'];

  // Handle user defined Thumb image
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
    $vars['thumb_image'] = theme('imagecache', '400x400', $vars['field_image'][0]['filepath'], $alt, $title );
  }   
  
  // Handle user defined Teaser text 
  if (empty($vars['field_summary'][0]['value'])) { 
    $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['node']->content['body']['#value'], 114, $chr = '...');    
  }
  else { 
    $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['field_summary'][0]['value'], 144, $chr = '...'); 
  } 
  
}

