<?php
/**
 * Preprocess variables for node-news.tpl.php
 */

function diwanee_smart_node_news_preprocess(&$vars) { 

  // Handle for date
  global $language; 
  if($language->name == 'Arabic') {
    $vars['node_created'] = format_date($vars['node']->created,'custom','Y m d');
  }
  else {
    $vars['node_created'] = format_date($vars['node']->created,'custom','d.m.Y');    
  }
  
  switch ($vars['build_mode']){
    case 'hometeaserlatestcampaings':
      // Handle front-page image
      if($vars['field_newsimage'][0]['filepath']) {        
        if ($vars['field_newsimage'][0]['data']['alt']) {
          $alt = $vars['field_newsimage'][0]['data']['alt'];
        }
        else {
          $alt = $vars['node']->title;     
        }
        if ($vars['field_newsimage'][0]['data']['title']) {
          $title = $vars['field_newsimage'][0]['data']['title'];
        }
        else {
          $title = $vars['node']->title;     
        }
        $vars['front_image'] = theme('imagecache', 'Campaing_Home_Thumb', $vars['field_newsimage'][0]['filepath'], $alt, $title );
        $vars['mobile_thumb_image'] = theme('imagecache', '400x200', $vars['field_newsimage'][0]['filepath'], $alt, $title );       
      }
      // Handle teaser from teaser-field or from body
      if(empty($vars['field_teaser'][0]['value'])){
        $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['node']->content['body']['#value'], 72, $chr = '...');
      }
      else {
        $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['field_teaser'][0]['value'], 72, $chr = '...');     
      }
      break;
    case 'teaser':
      // Handle teaser from teaser-field or from body
      if(empty($vars['field_teaser'][0]['value'])){
        $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['node']->content['body']['#value'], 800, $chr = '...');
      }
      else {
        $vars['teaser_text'] = $vars['field_teaser'][0]['value'];     
      }
      break;
    case 'hometeaser':  
        $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['node']->content['body']['#value'], 120, $chr = '...');      
      break;
      
    }
}
