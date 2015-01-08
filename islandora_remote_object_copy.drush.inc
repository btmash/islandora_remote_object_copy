<?php

/**
 * Implements hook_drush_command().
 */
function islandora_remote_object_copy_drush_command() {
  $items = array();

  $items['islandora_remote_object_copy_copy_single_record'] = array(
    'aliases' => array('iroc-csr'),
    'description' => 'Copy single fedora object from another fedora commons repo',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'options' => array(
      'fedora_url' => array(
        'description' => 'URL to the other fedora repo',
        'required' => TRUE,
      ),
      'fedora_username' => array(
        'description' => 'Username to access other fedora repo',
        'required' => TRUE,
      ),
      'fedora_password' => array(
        'description' => 'Password to access other fedora repo',
        'required' => TRUE,
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
