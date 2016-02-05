<?php

/*
 * @file
 * Administration form of the Module A configuration page
 */

/*
 * Return the name of the module specified in the .info file (nice name)
 */
function return_module_nice_name($module) {
  $result = system_get_info('module', $module);
    
  return $result['name'];
}

/*
 * Build the configuration page of Module A
 */
function modulea_admin_settings($form, &$form_state) {
  // Modules that implement the custom hook
  $modules = module_implements('modulea_config');
  
  //Final markup string
  $markup = "";
  
  foreach($modules as $module){
    $markup .= "<p>" . return_module_nice_name($module). " --> " .
                module_invoke($module, 'modulea_config') . "</p>";
  }
  
  $form['modulea_config_text'] = array(
    '#markup' => t('Module A configuration page.')
  );
  
  $form['modulea_hook_implementers'] = array(
    '#markup'=> $markup,
  );
  
  return system_settings_form($form);
}