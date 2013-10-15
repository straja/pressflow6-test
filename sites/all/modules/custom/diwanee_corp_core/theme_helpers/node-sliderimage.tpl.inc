<?php
/**
 * Preprocess variables for nd-sliderimage-slider.tpl.php
 */

function diwanee_node_sliderimage_preprocess(&$vars) {
  // Handle header images
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