<?php

/*
 * @file
 * Administration form of the Module A configuration page
 */

function modulea_admin_settings($form, &$form_state) {
  $form['modulea_config_text'] = array(
    '#markup' => t('Module A configuration page.')
  );
  
  $form['modulea_hook_implementers'] = array(
    '#markup'=> "<p>" . implode("</p><p>", module_invoke_all('modulea_config')) . "</p>",
  );
  
  return system_settings_form($form);
}