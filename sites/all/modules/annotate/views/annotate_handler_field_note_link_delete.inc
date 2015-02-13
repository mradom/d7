<?php

/**
 * Field handler to present a link to delete a annotation.
 */
class annotate_handler_field_note_link_delete extends views_handler_field {

  function construct() {
    parent::construct();
  }

  function render($row) {
    global $user;
    $note = new stdClass();
    $note->aid = $row->annotate_aid;
    $note->uid = $row->users_annotate_uid;

    // @see annotate_delete_access()
    if ($note->uid != $user->uid && $user->uid != 1) {
      return;
    }

    $options = array(
      'query' => drupal_get_destination()
    );

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');

    $uri = annotate_uri($note);
    $path = $uri['path'];
    return l($text, $path . "/delete", $options);
  }
}

