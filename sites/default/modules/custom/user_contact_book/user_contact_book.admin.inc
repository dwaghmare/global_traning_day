<?php
//pfe_cemhub_vendors.admin.inc
function user_contact_form($form, &$form_state, $user_contact = NULL) { 
	$form = array(); 
	global $user;
	
	$form['description'] = array(
		'#type' => 'markup',
		'#markup' => t('User Contact Form.'),
	);

	$vocabulary        = taxonomy_vocabulary_machine_name_load('contact_categories');  
	$terms             = taxonomy_get_tree($vocabulary->vid);
	$select_options[0] = t('Any');
	foreach ($terms as $term) {
		$select_options[$term->tid] = $term->name;
	}
	
    $form['type'] = array(
	  '#type' => 'select',
	  '#title' => t('Contact type :'),
	  '#description' => t('Contact type'),
	  '#attributes' => array('placeholder' => array('Enter Contact type')),
	  '#options'       => $select_options,
	  '#default_value' => isset($user_contact->type) ? $user_contact->type : '',
	  '#prefix' => '<div class="user-contact-type">',
	  '#suffix' => '</div>',
	  '#required' => TRUE,
	);
	
	$form['first_name'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Contact First Name :'),
	  '#description' => t('Contact First name'),
	  '#attributes' => array('placeholder' => array('Enter Contact First Name')),
	  '#size' => 60, 
      '#maxlength' => 60, 	  
	  '#default_value' => isset($user_contact->first_name) ? $user_contact->first_name : '',
	  '#prefix' => '<div class="user-contact-first-name">',
	  '#suffix' => '</div>',
	  '#required' => TRUE,
	);

	$form['last_name'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Contact Last Name :'),
	  '#description' => t('Contact Last name'),
	  '#attributes' => array('placeholder' => array('Enter Contact Last Name')),
	  '#size' => 60, 
      '#maxlength' => 60, 		  
	  '#default_value' => isset($user_contact->last_name) ? $user_contact->last_name : '',
	  '#prefix' => '<div class="user-contact-last-name">',
	  '#suffix' => '</div>',
	  '#required' => TRUE,
	);
	
	$form['email'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Contact email :'),
	  '#description' => t('Contact email'),
	  '#attributes' => array('placeholder' => array('Enter Contact email')),
	  '#size' => 60, 
      '#maxlength' => 60, 		  
	  '#default_value' => isset($user_contact->email) ? $user_contact->email : '',
	  '#prefix' => '<div class="user-contact-email">',
	  '#suffix' => '</div>',
	  '#required' => TRUE,
	);

	$form['mobile'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Contact mobile :'),
	  '#description' => t('Contact mobile'),
	  '#attributes' => array('placeholder' => array('Enter Contact mobile')),
	  '#size' => 60, 
      '#maxlength' => 10, 		  
	  '#default_value' => isset($user_contact->mobile) ? $user_contact->mobile : '',
	  '#prefix' => '<div class="user-contact-mobile">',
	  '#suffix' => '</div>',
	  '#required' => TRUE,
	  '#element_validate' => array('element_validate_number'),
	);

	$form['phone'] = array(
	  '#type' => 'textfield',
	  '#title' => t('Contact phone :'),
	  '#description' => t('Contact phone'),
	  '#size' => 60, 
      '#maxlength' => 10, 	  
	  '#attributes' => array('placeholder' => array('Enter Contact phone')),
	  '#default_value' => isset($user_contact->phone) ? $user_contact->phone : '',
	  '#prefix' => '<div class="user-contact-phone">',
	  '#suffix' => '</div>',
	  '#required' => TRUE,
	  '#element_validate' => array('element_validate_number'),
	);

	$form['terms_and_cond'] = array(
	  '#type' => 'checkbox',
	  '#title' => t('Contact terms and cond :'),
	  '#description' => t('Contact terms and cond'),
	  '#attributes' => array('placeholder' => array('Enter Contact terms and cond')),
	  '#default_value' => isset($user_contact->terms_and_cond) ? $user_contact->terms_and_cond : '',
	  '#prefix' => '<div class="user-terms-and-cond">',
	  '#suffix' => '</div>',
	  '#required' => TRUE,
	);


	$form['uid'] = array(
	  '#type' => 'hidden',
	  '#title' => t('Contact User Id :'),
	  '#description' => t('Contact User Id'),
	  '#attributes' => array('title' => array('User Id of Contact')),
	  '#default_value' => isset($user_contact->uid) ? $user_contact->uid : '',
	  '#prefix' => '<div class="user-id">',
	  '#suffix' => '</div>',
	  '#required' => TRUE,
	);

	$form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Submit'),
	);
	return $form;
}

function user_contact_form_validate($form, &$form_state) {

  if (empty($form_state['values']['title'])) {
    //form_set_error('pwd', t('Please enter Vendor Title.'));
  }
}

function user_contact_form_submit($form, &$form_state) {
  $user_contact = entity_ui_form_submit_build_entity($form, $form_state);
  $user_contact->save();
  drupal_set_message(t('@contacttitle has been saved.', array('@contacttitle' => $user_contact->title)));
}

