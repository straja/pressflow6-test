<?php
/**
 * Preprocess variables for node-media_kit.tpl.php
 */
function bpdiwanee_node_media_kit_preprocess(&$vars) {
  
  $vars['body'] = $vars['node']->content['body']['#value'];

  // Handle user defined Teaser text 
  if(empty($vars['field_teaser_body'][0]['value'])){ 
    $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['node']->content['body']['#value'], 114, $chr = '…');    
  }else{ 
    $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['field_teaser_body'][0]['value'], 144, $chr = '…'); 
  }

  // Handle user defined Thumb image
  if(isset($vars['field_brandsteaserthumbimage'][0]['filepath'])) {
    $vars['thumb_image'] = theme('imagecache', 'brands_thumb', $vars['field_brandsteaserthumbimage'][0]['filepath'], $vars['node']->title, $vars['node']->title);
  }
}
