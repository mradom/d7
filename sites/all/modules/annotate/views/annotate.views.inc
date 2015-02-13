<?php

/**
 * @file
 * Annotate Views support. Declares all the main tables to Views
 * @author Frans Kuipers http://drupal.org/user/103267
 */

/**
 * Implementation of hook_views_data().
 *
 * @see _annotate_get_visibility_list()
 */
function annotate_views_data() {
  $tables['annotate'] = array(
    'table' => array(
      'group' => t('Annotations'),
      'join' => array(
        'users' => array(
          'table' => 'annotate',
          'left_field' => 'uid',
          'field' => 'uid'
        ),
      ),
      'base' => array(
        'field' => 'note',
        'title' => t('Annotation'),
        'help' => t('Notes added as annotations to node content.'),
      ),
    ),
    // Fields definitions
    // Unique ID
    'aid' => array(
      'title' => t('Annotate ID'),
      'help' => t('ID of this annotation'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
      'extra' => array(
        array('field' => 'uid', 'value' => '***CURRENT_USER***', 'numeric' => TRUE),
      ),
    ),
    // Entity reference
    'entity_type' => array(
      'title' => t('Entity Type'),
      'help' => t('The entity type this note is annotated to.'),
      'field' => array(
        'handler' => 'views_handler_field',
      ),
    ),
    'entity_id' => array(
      'title' => t('Entity ID'),
      'help' => t('The entity ID this note is annotated to.'),
      'field' => array(
        'handler' => 'views_handler_field',
      ),
    ),
    // User reference
    'uid' => array(
      'title' => t('User'),
      'help' => t("The User ID of the note's author."),
      'relationship' => array(
        'base' => 'users',
        'base field' => 'uid',
        'handler' => 'views_handler_relationship',
        'label' => t('User'),
      ),
    ),
    'note' => array(
      'title' => t('Note'),
      'help' => t('The note text for this node'),
      // Information for displaying the note
      'field' => array(
        'handler' => 'views_handler_field_markup',
        'format' => array(
          'field' => 'note_format'
        ),
      ),
      'extra' => array(
        array('field' => 'uid', 'value' => '***CURRENT_USER***', 'numeric' => TRUE),
      ),
    ),
    'timestamp' => array(
      'title' => t('Post date'),
      'help' => t('Date and time of when the comment was posted.'),
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    ),
    'visibility' => array(
      'title' => t('Visibility'),
      'help' => t('Visibility of the note, 0=private, 1=editor, 2=other, 3=collaborators.'),
      'field' => array(
        'handler' => 'annotate_handler_field_visibility',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_in_operator',
        'options callback' => '_annotate_get_visibility_list',
      ),
    ),
    'delete_note' => array(
      'real field' => 'aid',
      'title' => t('Delete annotation'),
      'help' => t('Link to delete an annotation.'),
      'field' => array(
        'handler' => 'annotate_handler_field_note_link_delete',
      ),
    ),
    'entity_uri' => array(
      'real field' => 'entity_id',
      'title' => t('Entity URI'),
      'help' => t('Link to the referenced Entity.'),
      'field' => array(
        'handler' => 'annotate_handler_field_entity',
      ),
    ),
    'view_note' => array(
      'real field' => 'aid',
      'title' => t('View annotation'),
      'help' => t('Link to view an annotation.'),
      'field' => array(
        'handler' => 'annotate_handler_field_note_link_view',
      ),
    ),
    'edit_note' => array(
      'real field' => 'aid',
      'title' => t('Edit annotation'),
      'help' => t('Link to edit an annotation.'),
      'field' => array(
        'handler' => 'annotate_handler_field_note_link_edit',
      ),
    ),
    // uid alias to filter on current user
    'uid_current' => array(
      'real field' => 'uid',
      'title' => t('Current'),
      'help' => t('Filter the view to the currently logged in user.'),
      'filter' => array(
        'handler' => 'views_handler_filter_user_current',
        'type' => 'yes-no',
      ),
    ),
  );

  return $tables;
}

/**
 *  Implementation of hook_views_handlers().
 */
function annotate_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'annotate') . '/views',
    ),
    'handlers' => array(
      // field handler
      'annotate_handler_field_note' => array(
        'parent' => 'views_handler_field'
      ),
      'annotate_handler_field_visibility' => array(
        'parent' => 'views_handler_field'
      ),
      'annotate_handler_field_note_link_delete' => array(
        'parent' => 'views_handler_field'
      ),
      'annotate_handler_field_note_link_edit' => array(
        'parent' => 'views_handler_field'
      ),
    ),
  );
}
