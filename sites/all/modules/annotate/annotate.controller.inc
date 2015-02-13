<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of annotate
 *
 * @author clemens
 */
class AnnotateController extends DrupalDefaultEntityController {

  //put your code here
  function create($type, $entity_type, $entity_id) {
    global $user;
    // TODO: make this an entity call
    $node = node_load($entity_id);

    return (object) array(
          'aid' => '',
          'uid' => $user->uid,
          'type' => $type,
          'title' => '',
          'note' => '',
          'note_format' => 'plain_text',
          'entity_type' => $entity_type,
          'entity_id' => $entity_id,
          'timestamp' => 0,
    );
  }

  function save($annotate) {
    $transaction = db_transaction();

    try {
      $annotate->is_new = empty($annotate->aid);

      $annotate->timestamp = REQUEST_TIME;

      if ($annotate->is_new) {
        drupal_write_record('annotate', $annotate);
        $op = 'insert';
      }
      else {
        drupal_write_record('annotate', $annotate, 'aid');
        $op = 'update';
      }

      $function = 'field_attach_' . $op;

      $function('annotate', $annotate);

      module_invoke_all('entity_' . $op, 'annotate', $annotate);

      unset($annotate->is_new);

      db_ignore_slave();

      return $annotate;
    }
    catch (Exception $exception) {
      $transaction->rollback();
      watchdog_exception('annotate', $exception, NULL, WATCHDOG_ERROR);
    }
  }

  function delete($ids) {
    if (!empty($ids)) {
      $entity_type = 'annotate';
      $entities = $this->load($ids, array());
      $transaction = db_transaction();
      try {
        db_delete('annotate')
            ->condition('aid', $ids, 'IN')
            ->execute();
        foreach ($entities as $eid => $entity) {
          field_attach_delete($entity_type, $entity);
          module_invoke_all('entity_delete', $entity, $entity_type);
        }
        db_ignore_slave();
      }
      catch (Exception $e) {
        $transaction->rollback();
        watchdog_exception('annotate', $exception, NULL, WATCHDOG_ERROR);
        return FALSE;
      }

      cache_clear_all();
      $this->resetCache($ids);
    }
    return TRUE;
  }
}
?>
