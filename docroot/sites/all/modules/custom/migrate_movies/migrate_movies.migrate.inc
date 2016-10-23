<?php
/**
 * @file
 * Because the name of this file is the module name plus '.migrate.inc', when
 * hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded - thus, we don't need to implement your hook in the .module file.
 */

/*
 * Implements hook_migrate_api().
 */
function migrate_movies_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'imdb_movies_migrate' => array(
        'title' => t('Migrate IMDb Movies'),
      )
    ),
    'migrations' => array(
      'MoviesNode' => array(
        'class_name' => 'MoviesNodeMigration',
        'group_name' => 'imdb_movies_migrate',
      ),
    ),
  );
  return $api;
}