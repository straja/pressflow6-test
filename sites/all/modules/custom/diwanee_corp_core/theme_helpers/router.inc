<?php

/**
 * Implementation of hook_preprocess.
 */
function diwanee_preprocess(&$vars, $hook) { 
  diwanee_suggest_preprocessor($vars, $hook);
}

function diwanee_smart_preprocess(&$vars, $hook) { 
  diwanee_smart_suggest_preprocessor($vars, $hook);
}


/**
 * Checks for preprocessor files based on node type and includes them if available.
 */
function diwanee_suggest_preprocessor(&$vars, $hook) {
  print_r($vars['type']);
  if ($hook == 'page_header' || $hook == 'page_footer') {
    unset($vars['page_vars']['template_files']);    
    if (is_array($vars['page_vars'])) {
      foreach ($vars['page_vars'] as $var_key => $var_value) {
        $vars[$var_key] = $var_value;
      }
    }
    return;    
  }
  
  if (!empty($vars['type']) && $hook == 'node') {
    $inc_file = dirname(__FILE__) . '/node-' . $vars['type'] . '.tpl.inc';
    $func_name = 'diwanee_node_' . $vars['type'] . '_preprocess';
    
    if (file_exists($inc_file)) {
      require_once($inc_file);
      if (function_exists($func_name)) {
          $func_name($vars);
      }
    }
  }
}

function diwanee_smart_suggest_preprocessor(&$vars, $hook) {

  if ($hook == 'page_header' || $hook == 'page_footer') {
    unset($vars['page_vars']['template_files']);    
    if (is_array($vars['page_vars'])) {
      foreach ($vars['page_vars'] as $var_key => $var_value) {
        $vars[$var_key] = $var_value;
      }
    }
    return;    
  }
    
  if (!empty($vars['type']) && $hook == 'node') { 
    $inc_file = dirname(__FILE__) . "/diwanee_smart" . '/node-' . $vars['type'] . '.tpl.inc';
    $func_name = 'diwanee_smart_node_' . $vars['type'] . '_preprocess';
    if (file_exists($inc_file)) {
      require_once($inc_file);
      if (function_exists($func_name)) {
        $func_name($vars);
      }
    }
  }
    
}
