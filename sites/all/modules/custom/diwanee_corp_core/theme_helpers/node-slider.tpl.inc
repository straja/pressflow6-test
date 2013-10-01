<?php
/**
 * Preprocess variables for nd-slider-slider.tpl.php
 */

function diwanee_node_slider_preprocess(&$vars) {
  // Handle slider images
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
    $vars['slide_image'] = theme('imagecache', 'headbrandimages', $vars['field_image'][0]['filepath'], $alt, $title );
  }
}