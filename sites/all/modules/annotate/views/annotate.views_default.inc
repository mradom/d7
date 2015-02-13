<?php

/**
 * Implementation of hook_views_default_views().
 */
function annotate_views_default_views() {
  /*
   * View 'annotate_by_node'
   */
  $view = new view;
  $view->name = 'annotate_by_node';
  $view->description = 'Annotations by node';
  $view->tag = 'annotate';
  $view->base_table = 'annotate';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Annotations';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 5;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'timestamp' => 'timestamp',
    'note' => 'note',
    'view_note' => 'edit_note',
    'edit_note' => 'edit_note',
    'delete_note' => 'edit_note',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'note' => array(
      'align' => '',
      'separator' => '',
    ),
    'view_note' => array(
      'align' => '',
      'separator' => '',
    ),
    'edit_note' => array(
      'align' => '',
      'separator' => '&nbsp;',
    ),
    'delete_note' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['order'] = 'desc';
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Annotations: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'annotate';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'user';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Annotations: Post date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'annotate';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Annotations: Note */
  $handler->display->display_options['fields']['note']['id'] = 'note';
  $handler->display->display_options['fields']['note']['table'] = 'annotate';
  $handler->display->display_options['fields']['note']['field'] = 'note';
  $handler->display->display_options['fields']['note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['note']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['note']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['note']['empty_zero'] = 0;
  /* Field: Annotations: View annotation */
  $handler->display->display_options['fields']['view_note']['id'] = 'view_note';
  $handler->display->display_options['fields']['view_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['view_note']['field'] = 'view_note';
  $handler->display->display_options['fields']['view_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_note']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_note']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_note']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_note']['hide_alter_empty'] = 0;
  /* Field: Annotations: Edit annotation */
  $handler->display->display_options['fields']['edit_note']['id'] = 'edit_note';
  $handler->display->display_options['fields']['edit_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['edit_note']['field'] = 'edit_note';
  $handler->display->display_options['fields']['edit_note']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_note']['empty_zero'] = 0;
  /* Field: Annotations: Delete annotation */
  $handler->display->display_options['fields']['delete_note']['id'] = 'delete_note';
  $handler->display->display_options['fields']['delete_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['delete_note']['field'] = 'delete_note';
  $handler->display->display_options['fields']['delete_note']['label'] = 'Delete link';
  $handler->display->display_options['fields']['delete_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_note']['empty_zero'] = 0;

  /* Display: Annotations */
  $handler = $view->new_display('page', 'Annotations', 'page_1');
  $handler->display->display_options['path'] = 'node/%/annotate';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Annotations';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Annotations by node */
  $handler = $view->new_display('block', 'Annotations by node', 'block_1');
  $views[$view->name] = $view;

  /*
   * View 'annotate_by_user'
   */
  $view = new view;
  $view->name = 'annotate_by_user';
  $view->description = 'Annotations by user';
  $view->tag = 'annotate';
  $view->base_table = 'annotate';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'name' => 'name',
    'note' => 'note',
    'view_note' => 'edit_note',
    'edit_note' => 'edit_note',
    'delete_note' => 'edit_note',
    'entity_uri' => 'entity_uri',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'note' => array(
      'align' => '',
      'separator' => '',
    ),
    'view_note' => array(
      'align' => '',
      'separator' => '',
    ),
    'edit_note' => array(
      'align' => '',
      'separator' => '&nbsp;',
    ),
    'delete_note' => array(
      'align' => '',
      'separator' => '',
    ),
    'entity_uri' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['order'] = 'desc';
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'You don\'t have annotations yet.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'annotate';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'node';
  $handler->display->display_options['relationships']['nid']['required'] = 1;
  /* Relationship: Annotations: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'annotate';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'user';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: Annotations: Post date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'annotate';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'By';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Annotations: Note */
  $handler->display->display_options['fields']['note']['id'] = 'note';
  $handler->display->display_options['fields']['note']['table'] = 'annotate';
  $handler->display->display_options['fields']['note']['field'] = 'note';
  $handler->display->display_options['fields']['note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['note']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['note']['empty_zero'] = 0;
  /* Field: Annotations: View annotation */
  $handler->display->display_options['fields']['view_note']['id'] = 'view_note';
  $handler->display->display_options['fields']['view_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['view_note']['field'] = 'view_note';
  $handler->display->display_options['fields']['view_note']['label'] = '';
  $handler->display->display_options['fields']['view_note']['element_label_colon'] = FALSE;
  /* Field: Annotations: Edit annotation */
  $handler->display->display_options['fields']['edit_note']['id'] = 'edit_note';
  $handler->display->display_options['fields']['edit_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['edit_note']['field'] = 'edit_note';
  $handler->display->display_options['fields']['edit_note']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_note']['empty_zero'] = 0;
  /* Field: Annotations: Delete annotation */
  $handler->display->display_options['fields']['delete_note']['id'] = 'delete_note';
  $handler->display->display_options['fields']['delete_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['delete_note']['field'] = 'delete_note';
  $handler->display->display_options['fields']['delete_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_note']['empty_zero'] = 0;
  /* Field: Annotations: Entity URI */
  $handler->display->display_options['fields']['entity_uri']['id'] = 'entity_uri';
  $handler->display->display_options['fields']['entity_uri']['table'] = 'annotate';
  $handler->display->display_options['fields']['entity_uri']['field'] = 'entity_uri';
  $handler->display->display_options['fields']['entity_uri']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['external'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_uri']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_uri']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_uri']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_uri']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_uri']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_uri']['empty_zero'] = 0;
  $handler->display->display_options['fields']['entity_uri']['hide_alter_empty'] = 0;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['uid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['uid']['title'] = '%1';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: Annotations */
  $handler = $view->new_display('page', 'Annotations', 'page_1');
  $handler->display->display_options['path'] = 'user/%/annotate';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Annotations';
  $handler->display->display_options['menu']['description'] = 'Annotations regarding me';
  $handler->display->display_options['menu']['weight'] = '0';
  $views[$view->name] = $view;

  /*
   * View 'annotate_recent'
   */
  $view = new view;
  $view->name = 'annotate_recent';
  $view->description = 'Recent annotations';
  $view->tag = 'annotate';
  $view->base_table = 'annotate';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Recent annotations';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'name' => 'name',
    'note' => 'note',
    'edit_note' => 'edit_note',
    'delete_note' => 'edit_note',
    'entity_type' => 'entity_type',
    'entity_uri' => 'entity_uri',
    'view_note' => 'edit_note',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'note' => array(
      'align' => '',
      'separator' => '',
    ),
    'edit_note' => array(
      'align' => '',
      'separator' => '&nbsp;',
    ),
    'delete_note' => array(
      'align' => '',
      'separator' => '',
    ),
    'entity_type' => array(
      'align' => '',
      'separator' => '',
    ),
    'entity_uri' => array(
      'align' => '',
      'separator' => '',
    ),
    'view_note' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['order'] = 'desc';
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Annotations: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'annotate';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'user';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Annotations: Post date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'annotate';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'By';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Annotations: Note */
  $handler->display->display_options['fields']['note']['id'] = 'note';
  $handler->display->display_options['fields']['note']['table'] = 'annotate';
  $handler->display->display_options['fields']['note']['field'] = 'note';
  $handler->display->display_options['fields']['note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['note']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['note']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['note']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['note']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['note']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['note']['alter']['html'] = 1;
  $handler->display->display_options['fields']['note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['note']['empty_zero'] = 0;
  /* Field: Annotations: View annotation */
  $handler->display->display_options['fields']['view_note']['id'] = 'view_note';
  $handler->display->display_options['fields']['view_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['view_note']['field'] = 'view_note';
  $handler->display->display_options['fields']['view_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_note']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_note']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_note']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_note']['hide_alter_empty'] = 0;
  /* Field: Annotations: Edit annotation */
  $handler->display->display_options['fields']['edit_note']['id'] = 'edit_note';
  $handler->display->display_options['fields']['edit_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['edit_note']['field'] = 'edit_note';
  $handler->display->display_options['fields']['edit_note']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_note']['empty_zero'] = 0;
  /* Field: Annotations: Delete annotation */
  $handler->display->display_options['fields']['delete_note']['id'] = 'delete_note';
  $handler->display->display_options['fields']['delete_note']['table'] = 'annotate';
  $handler->display->display_options['fields']['delete_note']['field'] = 'delete_note';
  $handler->display->display_options['fields']['delete_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_note']['empty_zero'] = 0;
  /* Field: Annotations: Entity Type */
  $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['table'] = 'annotate';
  $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['entity_type']['hide_alter_empty'] = 0;
  /* Field: Annotations: Entity URI */
  $handler->display->display_options['fields']['entity_uri']['id'] = 'entity_uri';
  $handler->display->display_options['fields']['entity_uri']['table'] = 'annotate';
  $handler->display->display_options['fields']['entity_uri']['field'] = 'entity_uri';
  $handler->display->display_options['fields']['entity_uri']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['external'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_uri']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_uri']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_uri']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_uri']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['entity_uri']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_uri']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_uri']['empty_zero'] = 0;
  $handler->display->display_options['fields']['entity_uri']['hide_alter_empty'] = 0;
  /* Sort criterion: Annotations: Post date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'annotate';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';

  /* Display: Recent annotations block */
  $handler = $view->new_display('block', 'Recent annotations block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Annotations: Post date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'annotate';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Annotations: Note */
  $handler->display->display_options['fields']['note']['id'] = 'note';
  $handler->display->display_options['fields']['note']['table'] = 'annotate';
  $handler->display->display_options['fields']['note']['field'] = 'note';
  $handler->display->display_options['fields']['note']['label'] = '';
  $handler->display->display_options['fields']['note']['element_label_colon'] = FALSE;
  /* Field: Annotations: Entity URI */
  $handler->display->display_options['fields']['entity_uri']['id'] = 'entity_uri';
  $handler->display->display_options['fields']['entity_uri']['table'] = 'annotate';
  $handler->display->display_options['fields']['entity_uri']['field'] = 'entity_uri';
  $handler->display->display_options['fields']['entity_uri']['label'] = '';
  $handler->display->display_options['fields']['entity_uri']['element_label_colon'] = FALSE;

  /* Display: Recent annotations page */
  $handler = $view->new_display('page', 'Recent annotations page', 'page_1');
  $handler->display->display_options['path'] = 'annotate/recent';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Recent annotations';
  $handler->display->display_options['menu']['weight'] = '0';
  $views[$view->name] = $view;

  return $views;
}
