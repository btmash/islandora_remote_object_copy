<?php

class UncachedFedoraRepository extends FedoraRepository {
  /**
   * @see FedoraRepository::getObject()
   * @todo perhaps we should check if an object exists instead of catching
   *   the exception
   */
  public function getObject($id) {
    try {
      $object = new $this->objectClass($id, $this);
      return $object;
    }
    catch (RepositoryException $e) {
        throw $e;
    }
  }
}
