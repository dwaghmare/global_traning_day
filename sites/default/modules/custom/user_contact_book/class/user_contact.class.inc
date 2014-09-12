<?php
class UserContact extends Entity { public function __construct($values = array()) {
  parent::__construct($values, 'user_contact');
  }protected function defaultLabel() {
    return $this->name;
  }

  protected function defaultUri() {
    return array('path' => 'usercontacts/' . $this->cid);
  }
}

