<?php
/**
 * @file
 * movies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function movies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'imdb_movies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_movies';
  $view->human_name = 'IMDb Movies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Movie Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_genre' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Genre',
        'bef_filter_description' => '',
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_language' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Language',
        'bef_filter_description' => '',
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_years' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Year',
        'bef_filter_description' => '',
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_imdb_rating' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Rating',
        'bef_filter_description' => '',
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_title_text' => 'field_title_text',
    'field_movie_directors_text_string' => 'field_movie_directors_text_string',
    'field_genre' => 'field_genre',
    'field_imdb_rating' => 'field_imdb_rating',
  );
  $handler->display->display_options['style_options']['default'] = 'field_imdb_rating';
  $handler->display->display_options['style_options']['info'] = array(
    'field_title_text' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_movie_directors_text_string' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_genre' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imdb_rating' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Indexed Node: Movie title string */
  $handler->display->display_options['fields']['field_title_text']['id'] = 'field_title_text';
  $handler->display->display_options['fields']['field_title_text']['table'] = 'search_api_index_movies';
  $handler->display->display_options['fields']['field_title_text']['field'] = 'field_title_text';
  $handler->display->display_options['fields']['field_title_text']['label'] = 'Movie Title';
  $handler->display->display_options['fields']['field_title_text']['link_to_entity'] = 1;
  /* Field: Indexed Node: Movie director name text */
  $handler->display->display_options['fields']['field_movie_directors_text_string']['id'] = 'field_movie_directors_text_string';
  $handler->display->display_options['fields']['field_movie_directors_text_string']['table'] = 'search_api_index_movies';
  $handler->display->display_options['fields']['field_movie_directors_text_string']['field'] = 'field_movie_directors_text_string';
  $handler->display->display_options['fields']['field_movie_directors_text_string']['label'] = 'Director';
  $handler->display->display_options['fields']['field_movie_directors_text_string']['link_to_entity'] = 0;
  /* Field: Indexed Node: Genre */
  $handler->display->display_options['fields']['field_genre']['id'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['table'] = 'search_api_index_movies';
  $handler->display->display_options['fields']['field_genre']['field'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_genre']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_genre']['bypass_access'] = 0;
  /* Field: Indexed Node: Rating */
  $handler->display->display_options['fields']['field_imdb_rating']['id'] = 'field_imdb_rating';
  $handler->display->display_options['fields']['field_imdb_rating']['table'] = 'search_api_index_movies';
  $handler->display->display_options['fields']['field_imdb_rating']['field'] = 'field_imdb_rating';
  $handler->display->display_options['fields']['field_imdb_rating']['label'] = 'Imdb Rating';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_movies';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['min_length'] = '3';
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'field_movie_directors_text' => 'field_movie_directors_text',
    'title' => 'title',
  );
  /* Filter criterion: Indexed Node: Genre */
  $handler->display->display_options['filters']['field_genre']['id'] = 'field_genre';
  $handler->display->display_options['filters']['field_genre']['table'] = 'search_api_index_movies';
  $handler->display->display_options['filters']['field_genre']['field'] = 'field_genre';
  $handler->display->display_options['filters']['field_genre']['value'] = array();
  $handler->display->display_options['filters']['field_genre']['group'] = 1;
  $handler->display->display_options['filters']['field_genre']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_genre']['expose']['operator_id'] = 'field_genre_op';
  $handler->display->display_options['filters']['field_genre']['expose']['operator'] = 'field_genre_op';
  $handler->display->display_options['filters']['field_genre']['expose']['identifier'] = 'field_genre';
  $handler->display->display_options['filters']['field_genre']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_genre']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Language */
  $handler->display->display_options['filters']['field_language']['id'] = 'field_language';
  $handler->display->display_options['filters']['field_language']['table'] = 'search_api_index_movies';
  $handler->display->display_options['filters']['field_language']['field'] = 'field_language';
  $handler->display->display_options['filters']['field_language']['value'] = array();
  $handler->display->display_options['filters']['field_language']['group'] = 1;
  $handler->display->display_options['filters']['field_language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_language']['expose']['operator_id'] = 'field_language_op';
  $handler->display->display_options['filters']['field_language']['expose']['operator'] = 'field_language_op';
  $handler->display->display_options['filters']['field_language']['expose']['identifier'] = 'field_language';
  $handler->display->display_options['filters']['field_language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_language']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Years */
  $handler->display->display_options['filters']['field_years']['id'] = 'field_years';
  $handler->display->display_options['filters']['field_years']['table'] = 'search_api_index_movies';
  $handler->display->display_options['filters']['field_years']['field'] = 'field_years';
  $handler->display->display_options['filters']['field_years']['value'] = array();
  $handler->display->display_options['filters']['field_years']['group'] = 1;
  $handler->display->display_options['filters']['field_years']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_years']['expose']['operator_id'] = 'field_years_op';
  $handler->display->display_options['filters']['field_years']['expose']['operator'] = 'field_years_op';
  $handler->display->display_options['filters']['field_years']['expose']['identifier'] = 'field_years';
  $handler->display->display_options['filters']['field_years']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_years']['expose']['reduce'] = 0;

  /* Display: Movies Serch */
  $handler = $view->new_display('page', 'Movies Serch', 'page');
  $handler->display->display_options['display_description'] = 'IMDb movies search page.';
  $handler->display->display_options['path'] = 'movie-search';
  $export['imdb_movies'] = $view;

  return $export;
}
