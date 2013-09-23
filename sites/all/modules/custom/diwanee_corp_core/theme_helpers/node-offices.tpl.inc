<?php
/**
 * Preprocess variables for node-offices.tpl.php
 */
function diwanee_node_offices_preprocess(&$vars) { 
	global $base_url;
	$vars['title'] = $vars['title'];
	$vars['body'] = $vars['node']->content['body']['#value'];
	
        /* maybe we will need sometime, but for this pruduction it is needless
         * 
        $vars['teaser'] = $vars['node']->field_teaser_body[0]['value'];
	$vars['node_created'] = format_date($vars['created'], 'custom', "d.m.Y");
	$vars['link'] = 'node/'.$vars['nid'];
	$vars['latitude'] = $vars['node']->location['latitude'];
	$vars['longitude'] = $vars['node']->location['longitude'];
         * 
         */
}
