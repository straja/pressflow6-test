<?php

/**
 * Trim a text.
 */
function diwanee_corp_core_trim_text($str, $lim, $chr = '…'){
  // replacement candidate: node_teaser() 
  $str  = strip_tags($str);
  $str = preg_replace("/\&.{1,4}\;/", " ", $str); 
  $return  = views_trim_text(array('max_length'=>$lim, 'word_boundary'=>true, 'html'=>true), $str);
  $return  = check_plain($return);   
  $return  = trim($return);
  $return .= $chr;   
  return $return;
}
/**
 * Trim a text (arabic) to a certain number of characters, removing all HTML.
 * THIS FUNCTION IS REPLACED
function diwanee_corp_core_trim_text($str, $lim, $chr = '…')
{
  // remove any HTML or line breaks so these don't appear in the text
  $str = trim(  str_replace(array("\n", "\r", "\r\n"), ' ', strip_tags(html_entity_decode($str, ENT_QUOTES, 'UTF-8'))));
  
	// If length of string is less than $lim, return string
	if (strlen($str) <= $lim) return (substr($str, 0, strlen($str)));
	
	// Else, cut string down to size
	$str = mb_substr($str, 0, $lim - 3,"utf-8");
        $pos = strrpos($str, " ");
        return mb_substr($str, 0, $pos,"utf-8").$chr;
}
 */


/*
  Returns alias for given path
 */
function get_alias_by_path($path){
	$sql = "SELECT dst FROM {url_alias} WHERE src='".$path."'";
	$res = db_query($sql);
	$alias = db_fetch_object($res);
	if($alias->dst == NULL){
		return $path;
	}else{
		return $alias->dst;
	}
}
