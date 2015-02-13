<?php

/**
 * Field handler to present a link node translate.
 */
class annotate_handler_field_note extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['format'] = 'note_format';
  }

  /**
   * Called to render this field.
   */
  function render($row) {
    // render the annotation note
    $value = $row->note;
    $format = $row->annotate_note_format;
    if ($value) {
      return check_markup($value, $format, FALSE);
    }
  }
}
