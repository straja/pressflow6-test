<?php

/**
 * Preprocess function for slider
 * @param type $vars
 */
function diwanee_node_sliderimages_preprocess(&$vars) {
    //Adding js and css
    drupal_add_js(drupal_get_path('module', 'slider') . '/js/slider.js');
    drupal_add_css(drupal_get_path('module', 'slider') . '/css/slider.css');

    // Handle header images
    for($i=0; $i<count($vars['field_image']); $i++) {
       if(isset($vars['field_image'][$i]['filepath'])) {
         if ($vars['field_image'][$i]['data']['alt']) {
           $alt = $vars['field_image'][$i]['data']['alt'];
         }
         else {
           $alt = $vars['node']->title;     
         }
         if ($vars['field_image'][$i]['data']['title']) {
           $title = $vars['field_image'][$i]['data']['title'];
         }
         else {
           $title = $vars['node']->title;     
         }
         
         //TOBE: $vars['slider_images'][] = theme('imagecache', 'sliderimages', $vars['field_image'][$i]['filepath'], $alt, $title );
         $vars['slider_images'][] = '<img src="' . base_path() . $vars['field_image'][$i]['filepath'] . '" />';
       }
    }
}
