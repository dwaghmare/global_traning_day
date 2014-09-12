<?php
/**
 * @file
 * contact_book_helper_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function contact_book_helper_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_user_contact().
 */
function contact_book_helper_feature_default_user_contact() {
  $items = array();
  $items['6'] = entity_import('user_contact', '{
    "cid" : "6",
    "type" : "3",
    "first_name" : "Tom",
    "last_name" : "Jack",
    "email" : "Tomjack@gmail.com",
    "mobile" : "9878987987",
    "phone" : "9878987987",
    "terms_and_cond" : "1",
    "uid" : "1",
    "bundle" : null,
    "rdf_mapping" : []
  }');
  $items['7'] = entity_import('user_contact', '{
    "cid" : "7",
    "type" : "1",
    "first_name" : "Mr Tom",
    "last_name" : "Jack",
    "email" : "tom.jack@tcs.com",
    "mobile" : "9878987987",
    "phone" : "9878987987",
    "terms_and_cond" : "1",
    "uid" : "1",
    "bundle" : null,
    "rdf_mapping" : []
  }');
  $items['8'] = entity_import('user_contact', '{
    "cid" : "8",
    "type" : "3",
    "first_name" : "Dinesh",
    "last_name" : "TK",
    "email" : "dineshtk@firstpost.com",
    "mobile" : "9876547896",
    "phone" : "9878987987",
    "terms_and_cond" : "1",
    "uid" : "11",
    "bundle" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
