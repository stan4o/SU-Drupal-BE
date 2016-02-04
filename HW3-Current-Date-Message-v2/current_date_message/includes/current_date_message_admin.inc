<?php

/*
 * Settings callback for Current Date Message - Tab "Default"
 */

function current_date_message_form_default ($form){
  
  // Enable/disable the functionality
  $form['cdm_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable the module',
    '#default_value' => variable_get('cdm_is_enabled', 0)
  );
  
  // Select the type fo the message
  $form['cdm_message_type'] = array(
    '#type' => 'select',
    '#title' => 'Select the type of the message',
    '#options' => array(
      'status' => 'Status',
      'warning' => 'Warning',
      'error' => 'Error'
    ),
    '#default_value' => variable_get('cdm_message_type', 'status')
  );
  
  return system_settings_form($form);
}

/*
 * Settings callback for Current Date Message - Tab "Advanced"
 */

function current_date_message_form_advanced ($form) {
  
  // Show the message for anonymous users
  $form['cdm_show_for_anonymous'] = array(
    '#type' => 'checkbox',
    '#title' => 'Show for anonymous users',
    '#default_value' => variable_get('cdm_show_for_anonymous', 0)
  );
  
  return system_settings_form($form);
}