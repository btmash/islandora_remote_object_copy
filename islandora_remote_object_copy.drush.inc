<?php

/**
 * Implements hook_drush_command().
 */
function islandora_remote_object_copy_drush_command() {
  $items = array();

  $items['islandora_remote_object_copy_copy_single_record'] = array(
    'aliases' => array('iroc-csr'),
    'description' => 'Copy single fedora object from another fedora commons repo',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    'options' => array(
      'fedora_url' => array(
        'description' => 'URL to the other fedora repo. If not provided, will use settings via UI.',
        'required' => FALSE,
      ),
      'fedora_username' => array(
        'description' => 'Username to access other fedora repo',
        'required' => FALSE,
      ),
      'fedora_password' => array(
        'description' => 'Password to access other fedora repo',
        'required' => FALSE,
      ),
      'fedora_pid' => array(
        'description' => 'Fedora object ID from other fedora repo',
        'required' => TRUE,
      ),
      'parent_collection' => array(
        'description' => 'Fedora collection ID in current repo you wish to add object to.',
        'required' => TRUE,
      ),
    ),
  );

  return $items;
}

/**
 * Copies single fedora object from secondary fedora repo.
 */
function drush_islandora_remote_object_copy_copy_single_record() {
  // Not sure but global user still does not get assigned super user.
  // Explicitly assigning priviledged user.
  global $user;
  $current_user = $user;
  $user = user_load(drush_get_option('user', 1));

  $fedora_url = drush_get_option('fedora_url', variable_get('islandora_remote_object_copy_uri', ''));
  $fedora_account = new stdClass();
  $fedora_account->user = drush_get_option('fedora_username', variable_get('islandora_remote_object_copy_username', ''));
  $fedora_account->pass = drush_get_option('fedora_password', variable_get('islandora_remote_object_copy_password', ''));
  $parent_collection = drush_get_option('parent_collection');
  $fedora_pid = drush_get_option('fedora_pid');
  islandora_remote_object_copy_copy_single_object($fedora_url, $fedora_account, $parent_collection, $fedora_pid);

  $user = $current_user;
}
