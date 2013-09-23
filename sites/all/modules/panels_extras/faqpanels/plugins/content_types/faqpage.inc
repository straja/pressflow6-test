<?php
// $Id$ .inc,v 1.0 2011/02/07 11:20:07 chriscalip Exp $
/**
 * @file
 * Provides additional content type CCK Email Contact form for panels use
 */

if (module_exists('faq')) {
  /**
   * Plugins are described by creating a $plugin array which will be used
   * by the system that includes this file.
   */
  $plugin = array(
    'single' => TRUE,
    'title' => t('FAQ page'),
    // @todo provide png file
    //'icon' => 'icon_goes_here.png',
    'description' => t('Display the page generated by the faq module'),
    'category' => t('Panels Extras'),
  );
}

/**
 * Render the custom content type.
 */
function faqpanels_faqpage_content_type_render($subtype, $conf, $panel_args, $context) {
  // Build the content type block.
  $block = new stdClass();
  $block->module = 'form';
  $block->delta   = $panel_args['tid'];
  $block->content = faq_page($panel_args['tid'], $panel_args['faq_display']);
  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function faqpanels_faqpage_content_type_edit_form(&$form, &$form_state) {
  // @todo placeholder stuff for now
}

/**
 * Submit handler for contact form.
 */
function faqpanels_faqpage_content_type_edit_form_submit(&$form, &$form_state) {
  // @todo placeholder stuff for now
}

/**
 * Returns the administrative title for a type.
 */
function faqpanels_faqpage_content_type_admin_title($subtype, $conf, $context) {
  return t('FAQ Page');
}