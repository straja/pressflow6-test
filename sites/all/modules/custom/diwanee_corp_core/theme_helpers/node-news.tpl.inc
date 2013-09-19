<?php
/**
 * Preprocess variables for node-news.tpl.php
 */

function diwanee_node_news_preprocess(&$vars) { 
  
  switch ($vars['build_mode']){
    case 'mainnews':
        // Handle teaser from teaser-field or from body
        // Handle user defined Teaser text 
        if (empty($vars['field_summary'][0]['value'])) { 
          $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['node']->content['body']['#value'], 280, $chr = '...');    
        }
        else { 
          $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['field_summary'][0]['value'], 280, $chr = '...'); 
        }

    case 'datetitle':
        // Handle date for teaser
        if(!empty($vars['field_date'][0]['value'])){
            $vars['teaser_date'] = format_date(strtotime($vars['field_date'][0]['value']), 'custom', 'd.m.Y.');
        } else {
            $vars['teaser_date'] = 'no date';
        }
      break;
    }
}
