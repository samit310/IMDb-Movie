<?php
/**
 * @file
 * movies.features.inc
 */

/**
 * Implements hook_views_api().
 */
function movies_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function movies_node_info() {
  $items = array(
    'movies' => array(
      'name' => t('Movies'),
      'base' => 'node_content',
      'description' => t('Movies content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function movies_default_search_api_index() {
  $items = array();
  $items['movies'] = entity_import('search_api_index', '{
    "name" : "Movies",
    "machine_name" : "movies",
    "description" : null,
    "server" : "apache_solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "movies" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "body:value" : { "type" : "text" },
        "field_actors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_awards" : { "type" : "text" },
        "field_countries" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_genre" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_imdb_id" : { "type" : "text" },
        "field_imdb_rating" : { "type" : "decimal" },
        "field_imdb_votes" : { "type" : "text" },
        "field_language" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_metascore" : { "type" : "text" },
        "field_movie_directors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_movie_directors_text" : { "type" : "text" },
        "field_movie_directors_text_string" : { "type" : "string" },
        "field_rated" : { "type" : "text" },
        "field_released_date" : { "type" : "text" },
        "field_response" : { "type" : "text" },
        "field_title_text" : { "type" : "string" },
        "field_type" : { "type" : "text" },
        "field_writers" : { "type" : "text" },
        "field_years" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_rated" : true,
              "field_writers" : true,
              "field_metascore" : true,
              "field_imdb_id" : true,
              "field_imdb_rating" : true,
              "field_awards" : true,
              "field_type" : true,
              "field_response" : true,
              "field_imdb_votes" : true,
              "body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_rated" : true,
              "field_writers" : true,
              "field_metascore" : true,
              "field_imdb_id" : true,
              "field_imdb_rating" : true,
              "field_awards" : true,
              "field_type" : true,
              "field_response" : true,
              "field_imdb_votes" : true,
              "body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_rated" : true,
              "field_writers" : true,
              "field_metascore" : true,
              "field_imdb_id" : true,
              "field_imdb_rating" : true,
              "field_awards" : true,
              "field_type" : true,
              "field_response" : true,
              "field_imdb_votes" : true,
              "body:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_rated" : true,
              "field_writers" : true,
              "field_metascore" : true,
              "field_imdb_id" : true,
              "field_imdb_rating" : true,
              "field_awards" : true,
              "field_type" : true,
              "field_response" : true,
              "field_imdb_votes" : true,
              "body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function movies_default_search_api_server() {
  $items = array();
  $items['apache_solr'] = entity_import('search_api_server', '{
    "name" : "Apache Solr",
    "machine_name" : "apache_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "log_query" : 0,
      "log_response" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
