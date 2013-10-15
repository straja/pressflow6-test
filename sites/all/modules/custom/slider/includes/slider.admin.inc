<?php
// $Id$

/**
 * @file
 * Administration page callbacks for slider module
 */

/*
 * Form builder. Configure slider image upload.
 * 
 * @ingroup forms
 * @see system_setings_form()
 */
function slider_admin() {   
    $form['slider_title'] = array(
        '#type' => 'textfield',
        '#size' => 60,
        '#maxlength' => 128,
        '#ahah["event"]' => 'blur',
        '#required' => TRUE,
        '#description' => t('Title of slider image')
    );
    
    $form['slider_image'] = array(
        '#atributes' => array( 'enctype' => 'multipart/form-data' )
    );
    $form['slider_image']['image'] = array(
        '#type' => 'file',
        '#size' => 60
    );
    
    $form['slider_image']['submit'] = array(
        '#value' => t('Upload'),
        '#type' => 'submit',
        '#title' => t('Upload'),
        '#weight' => 1,
        '#ahah' => array(
            'event' => 'click',
            'path' => 'slider/js',
            'wrapper' => 'edit-image-wrapper',
            'method' => 'replace',
            'effect' => 'fade',
            'progress' => array(
                'type' => 'bar',
                'message' => t('Loading...')
            )
        )
    );
    
    return system_settings_form($form); 
} // end slider_admin

/*
 * Validation for administration settigns of this module
 */
/*TODO: better solution - is it content type with field image.
function slider_admin_validate() {
    $cttype = $form_state['values']['slider_cttype'];
    $table = 'content_type_' . $cttype;
    if(!db_table_exists($table)){
        form_set_error('slider_cttype', t('You must choose existing content cype.'));
    }
} // end slider_admin_validate

/**
 * Handel submission of the slider image form and saving
 * of the data to the database
 */
function slider_entry_form_submit($form, $form_state) {
    global $user;
    
    $image = $form_state['values']['image'];
    $nid = $form_state['values']['nid'];
    
    db_query("DELETE FROM {slider} WHERE nid = %d AND uid = %d", $nid, $user->uid);
    db_query("INSERT INTO {slider} (nid, uid, image, created)
              VALUES (%d, %d, %s, %d)", $nid, $user->uid, $image, time());
    drupal_set_message(t('Your image for slider has been saved.'));
} // end slider_entry_form_submit

/**
 * Implementation of hook_nodeapi()
 *
function slider_nodeapi(&$node, $op, $teaser, $page) {
    global $user;
    switch ($op){
        // The 'view' operation means the node is about to be displayed.
        case 'view':
            // Abort if only the node summary (teaser) is being displayed.
            if(!$page){
                break;
            }
            // Get the current slider for this node from the database
            // and store it in the node object.
            $result = db_query('SELECT nid  FROM {node} WHERE nid = %d', $node->nid);
            $node->slider = db_result($result);
            
            // Add our form as a content item.
            $node->content['slider_form'] = array(
                '#value' => drupal_get_form('slider_entry_form', $node),
                '#weigth' => 10
            );
            break;
        case 'delete':
            db_query('DELETE FROM {node} WHERE nid = %d', $node->nid);
            break;
    }
}