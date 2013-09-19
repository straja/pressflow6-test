<?php
/**
 * Preprocess variables for node-jobs.tpl.php
 */

function bpdiwanee_node_jobs_preprocess(&$vars) { 
    
  // Handle teaser from teaser-field or from body

        if(empty($vars['field_teaser'][0]['value'])){
          $vars['teaser_text'] = diwanee_corp_core_trim_text( $vars['node']->content['body']['#value'], 800, $chr = '…');
        }else{
          $vars['teaser_text'] = $vars['field_teaser'][0]['value'];     
        }
      
     }
