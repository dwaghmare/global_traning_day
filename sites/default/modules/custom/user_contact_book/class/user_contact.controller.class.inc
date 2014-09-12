<?php
class UserContactController extends EntityAPIController { public function __construct($entityType) { parent::__construct($entityType);
}public function save($entity, DatabaseTransaction$transaction = NULL) {
  if (isset($entity->is_new)) {
    $entity->created = REQUEST_TIME;
  }

  $entity->changed = REQUEST_TIME;
  return parent::save($entity, $transaction);
}

public function create(array$values = array()) {
  global $user;

  $values += array(
    'cid' => '',
    'uid' => $user->uid,
  );

  $user_contact = parent::create($values);
  return $user_contact;
}
}

