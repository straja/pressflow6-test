<?php
/**
 * Preprocess variables for node-news.tpl.php
 */

function diwanee_smart_node_slide_preprocess(&$vars) { 
    
         
  // Handle front-page image
  if($vars['field_image'][0]['filepath']) {
    $vars['slide_image'] = $vars['field_image'][0]['filepath'];
  } 
  // Handle Custom Link
  if($vars['field_custom_link']) {
    $vars['custom_link'] = $vars['field_custom_link'][0]['value'];
  } 
   

}
