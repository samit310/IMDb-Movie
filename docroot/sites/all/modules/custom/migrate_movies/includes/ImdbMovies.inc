<?php
/**
 * @file
 * Handlers for IMDb Movies migrations.
 */

/**
 * Class MoviesNodeMigration handles the migration of the IMDb Movies from Json URL.
 */
class MoviesNodeMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    // Json URL for IMDb Movies.
    $list_url = 'https://gist.githubusercontent.com/kasisnu/3022b00aead25810b794/raw/05d573ac97071e34b0ee89c2ee4470dc9042b016/use_the_force.json';

    // Human-friendly description of your migration process. 
    $this->description = t('Migrate IMDb movies from the Json URL to Movies Content type.');

    /**
     * $list_url: Movies data Json URL
     * 'imdb_id': Unique id
     * '$this->fields()':All fileds maped with Movies Content type.
     */
    $this->source = new MigrateSourceJSON($list_url, 'imdb_id', $this->fields());

    $this->map = new MigrateSQLMap($this->machineName, array(
      'imdb_id' => array(
        'type' => 'varchar',
        'length' => 255,
        'description' => 'ID',
        'not null' => TRUE,
      ),
        ), MigrateDestinationNode::getKeySchema()
    );

    $this->destination = new MigrateDestinationNode('movies');

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'plot');
    $this->addFieldMapping('field_image', 'poster');
    $this->addFieldMapping('field_writers', 'writer');
    $this->addFieldMapping('field_metascore', 'metascore');
    $this->addFieldMapping('field_imdb_id', 'imdb_id');
    $this->addFieldMapping('field_awards', 'awards');
    $this->addFieldMapping('field_runtime', 'runtime');
    $this->addFieldMapping('field_type', 'type');
    $this->addFieldMapping('field_response', 'response');
    $this->addFieldMapping('field_imdb_votes', 'imdb_votes');
    $this->addFieldMapping('field_rated', 'rated');
    $this->addFieldMapping('field_released_date', 'released');
    $this->addFieldMapping('field_imdb_rating', 'imdb_rating');
    
    /**
     * Term reference Fields with Unlimited values
     * field_language, field_countries, field_movie_directors, field_genre, field_actors
     */
    $this->addFieldMapping('field_language', 'language')->separator(',');
    $this->addFieldMapping('field_language:create_term')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_language:ignore_case')
        ->defaultValue(TRUE);

    $this->addFieldMapping('field_countries', 'country')->separator(',');
    $this->addFieldMapping('field_countries:create_term')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_countries:ignore_case')
        ->defaultValue(TRUE);

    $this->addFieldMapping('field_movie_directors', 'director')->separator(',');
    $this->addFieldMapping('field_movie_directors:create_term')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_movie_directors:ignore_case')
        ->defaultValue(TRUE);

    $this->addFieldMapping('field_genre', 'genre')->separator(',');
    $this->addFieldMapping('field_genre:create_term')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_genre:ignore_case')
        ->defaultValue(TRUE);

    $this->addFieldMapping('field_actors', 'actors')->separator(',');
    $this->addFieldMapping('field_actors:create_term')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_actors:ignore_case')
        ->defaultValue(TRUE);

    /**
     * Term reference Fields with 1 values
     * field_years
     */
    $this->addFieldMapping('field_years', 'year');
    $this->addFieldMapping('field_years:create_term')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_years:ignore_case')
        ->defaultValue(TRUE);
    
    // Default Fields
    $this->addFieldMapping('uid');
    $this->addFieldMapping('created');
    $this->addFieldMapping('changed');
    $this->addFieldMapping('status');
    $this->addFieldMapping('language')->defaultValue('en');

    // Do not migrate
    $this->addFieldMapping('promote')->issueGroup(t('DNM'));
    $this->addFieldMapping('sticky')->issueGroup(t('DNM'));
    $this->addFieldMapping('revision')->issueGroup(t('DNM'));
    $this->addFieldMapping('log')->issueGroup(t('DNM'));
    $this->addFieldMapping('tnid')->issueGroup(t('DNM'));
    $this->addFieldMapping('translate')->issueGroup(t('DNM'));
    $this->addFieldMapping('revision_uid')->issueGroup(t('DNM'));
    $this->addFieldMapping('is_new')->issueGroup(t('DNM'));
    $this->addFieldMapping('body:summary')->issueGroup(t('DNM'));
    $this->addFieldMapping('body:format')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:file_class')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:preserve_files')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:destination_dir')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:destination_file')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:file_replace')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:source_dir')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:urlencode')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:alt')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_image:title')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_tags')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_tags:source_type')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_tags:create_term')->issueGroup(t('DNM'));
    $this->addFieldMapping('field_tags:ignore_case')->issueGroup(t('DNM'));
    $this->addFieldMapping('path')->issueGroup(t('DNM'));
    $this->addFieldMapping('comment')->issueGroup(t('DNM'));
  }

  /**
   * Return the fields (this is cleaner than passing in the array in the MigrateSourceList class above)
   * @return array
   */
  function fields() {
    return array(
      'plot' => 'The body content.',
      'rated' => 'Movie rated',
      'language' => 'Movie Language',
      'title' => 'Title of the Movie',
      'country' => 'Country',
      'writer' => 'Movie Writer',
      'year' => 'Movie year',
      'metascore' => 'metascore',
      'imdb_id' => 'IMDb id',
      'director' => 'Movies director',
      'released' => 'Released Date',
      'imdb_rating' => 'IMDb Rating',
      'awards' => 'Awards',
      'poster' => 'Movies poster image',
      'genre' => 'Genre',
      'actors' => 'Movies actors',
      'runtime' => 'Runtime',
      'type' => 'Type',
      'response' => 'Response',
      'imdb_votes' => 'Movie IMDb Vote'
    );
  }
}
