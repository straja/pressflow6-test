<?php
/**
 * Preprocess variables for nd-slider-slider.tpl.php
 */

function diwanee_node_slider_preprocess(&$vars) { 
      
  // Handle slider images
  if($vars['field_gallery'][0]['filepath']) {
    $vars['slide_images'] = $vars['field_gallery'][0]['filepath'];
  }
  
  
}