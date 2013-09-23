<?php
// $Id$ contactemail.inc,v 1.0 2011/01/28 16:50:48 chriscalip Exp $

/**
 * @file
 * Provides additional page manager tasks CCK Email Contact form for panels use
 */

/**
 * Specialized implementation of hook_page_manager_task_tasks(). See api-task.html for
 * more information.
 */
function emailpanels_contactemail_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',

    'title' => t('CCK Email field generated form page'),
    'admin title' => t('CCK Email field generated form page'),
    'admin description' => t('when enabled, this overrides the default Drupal behavior of the cck email field generated form page at <em>email/%node/%field_name</em>'),
    'admin path' => 'email/%node/%field_name',

    // Menu hooks so that we can alter the email/%node/%field_name menu entry to point to us.
    'hook menu' => 'emailpanels_contactemail_menu',
    'hook menu alter' => 'emailpanels_contactemail_menu_alter',

    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => 'emailpanels_contactemail_get_arguments',
    'get context placeholders' => 'emailpanels_contactemail_get_contexts',

    // Allow this to be enabled or disabled:
    'disabled' => variable_get('emailpanels_contactemail_disabled', TRUE),
    'enable callback' => 'emailpanels_contactemail_enable',
  );
}

/**
 * Callback defined by emailpanels_contactemail_page_manager_tasks().
 *
 * Alter the cck email generated contact form page so that the contact form page comes to us rather than the
 * normal cck email contact form process.
 */
function emailpanels_contactemail_menu_alter(&$items, $task) {
  if (variable_get('emailpanels_contactemail_disabled', TRUE)) {
    return;
  }

  $callback = $items['email/%/%']['page callback'];
  // Override the node edit handler for our purpose.
  if ($callback == 'email_mail_page' || variable_get('page_manager_override_anyway', FALSE)) {
    $items['email/%/%']['page callback'] = 'emailpanels_contactemail';
    $items['email/%/%']['file path'] = $task['path'];
    $items['email/%/%']['file'] = $task['file'];
  }
  else {
    variable_set('emailpanels_contactemail_disabled', TRUE);
    if (!empty($GLOBALS['emailpanels_enabling_contactemail'])) {
      drupal_set_message(t('Page manager module is unable to enable email/%node/%field_name because some other module already has overridden with %callback.', array('%callback' => $callback)), 'warning');
    }
    return;
  }
}

/**
 * Entry point for our overridden cck email generated contact form page.
 *
 * This function asks its assigned handlers who, if anyone, would like
 * to run with it. If no one does, it passes through to CCK email field, which is email_mail_page().
 */
function emailpanels_contactemail($nid, $field_name) {
  // Load my task plugin
  $task = page_manager_get_task('contactemail');

  ctools_include('context');
  ctools_include('context-task-handler');

  // @todo add ability to accept the node and field name context; well maybe just the node context

  // is it worth the performance hit to include node as a context? if so switch
  //$contexts = emailpanels_contactemail_get_contexts($task, '', array($nid));
  $contexts = emailpanels_contactemail_get_contexts($task, '', array());

  $output = ctools_context_handler_render($task, '', $contexts, array('nid' => $nid, 'field_name' => $field_name));
  if ($output !== FALSE) {
    return $output;
  }

  // fallback to the default email contact form page handler
  // assume the cck email module is on.
  $function = 'email_mail_page';

  foreach (module_implements('page_manager_override') as $module) {
    $call = $module . '_page_manager_override';
    if (($rc = $call('contactemail')) && function_exists($rc)) {
      $function = $rc;
      break;
    }
  }
  // Otherwise, fall back.
  return $function($nid, $field_name);
}

/**
 * Callback to get arguments provided by this task handler.
 *
 * Since this is the node edit and there is no UI on the arguments, we
 * create dummy arguments that contain the needed data.
 */
function emailpanels_contactemail_get_arguments($task, $subtask_id) {
  return array(
    array(
      'keyword' => 'node',
      'identifier' => t('Node'),
      'id' => 1,
      'name' => 'nid',
      'settings' => array(),
    ),
  );
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function emailpanels_contactemail_get_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(emailpanels_contactemail_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function emailpanels_contactemail_enable($cache, $status) {
  variable_set('emailpanels_contactemail_disabled', $status);
  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['emailpanels_enabling_contactemail'] = TRUE;
  }
}