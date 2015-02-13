<?php

/**
 * Field handler to present a link node translate.
 */
class annotate_handler_field_entity extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['entity_type'] = 'entity_type';
  }

  /**
   * Called to render this field.
   */
  function render($row) {
    // render the annotation note
    $entity_type = $row->annotate_entity_type;
    $entity_id = $row->annotate_entity_id;

    $entity = reset(entity_load($entity_type, array($entity_id)));
    if (!empty($entity)) {    
      $uri = entity_uri($entity_type, $entity);
      $title = entity_label($entity_type, $entity);
      return l($title, $uri['path'], $uri['options']);
    }
  }
}
