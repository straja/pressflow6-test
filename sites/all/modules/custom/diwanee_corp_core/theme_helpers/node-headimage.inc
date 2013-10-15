<?php
/**
 * Preprocess variables for nd-slider-slider.tpl.php
 */

function diwanee_node_headimage_preprocess(&$vars) { 
      
  // Handle slider images
  if($vars['field_image'][0]['filepath']) {
    $vars['head_image'] = $vars['field_image'][0]['filepath'];
  }
  
  
}