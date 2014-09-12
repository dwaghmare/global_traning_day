<?php
/**
 * @file
 * contact_book_helper_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function contact_book_helper_feature_taxonomy_default_vocabularies() {
  return array(
    'contact_categories' => array(
      'name' => 'Contact categories',
      'machine_name' => 'contact_categories',
      'description' => 'Contact categories list.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
