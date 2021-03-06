<?
/**
 * @file
 * Contains Batch API callbacks used during installation.
 */

/**
 * BatchAPI callback. Create Status Terms.
 */
function _ntxuva_create_status($operation, &$context) {

  // Get the vocabulary ID.
  $vid = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = 'status'")->fetchField();

  // Define the terms, with description and color:
  $terms[0] = array(
    'Novos',
    'This is just a description which should be replaced',
    '#FF0000',
    'pause',
    'ntxuva-font',
  );
  $terms[1] = array(
    'Em progresso',
    'This is just a description which should be replaced',
    '#FFA500',
    'play',
    'ntxuva-font',
  );
  $terms[3] = array(
    'Resolvidos',
    'This is just a description which should be replaced',
    '#008000',
    'checkmark',
    'ntxuva-font',
  );
  $terms[4] = array(
    'Arquivados',
    'This is just a description which should be replaced',
    '#5F9EA0',
    'drawer',
    'ntxuva-font',
  );

  // You may customize those entries:
  $terms[5] = array(
    'dummy',
    'This is just a description which should be replaced',
    '#FFFFFF',
    '',
    '',
  );
  $terms[6] = array(
    'dummy',
    'This is just a description which should be replaced',
    '#FFFFFF',
    '',
    '',
  );
  $terms[7] = array(
    'dummy',
    'This is just a description which should be replaced',
    '#FFFFFF',
    '',
    '',
  );
  $terms[8] = array(
    'dummy',
    'This is just a description which should be replaced',
    '#FFFFFF',
    '',
    '',
  );
  $terms[9] = array(
    'dummy',
    'This is just a description which should be replaced',
    '#FFFFFF',
    '',
    '',
  );

  foreach ($terms as $parent) {
    // Create the parent term.
    $term['vid'] = $vid;
    $term['name'] = $parent[0];
    $term['description'] = $parent[1];
    $term['field_status_hex'][LANGUAGE_NONE][0]['rgb'] = $parent[2];
    $term['field_status_icon'][LANGUAGE_NONE][0]['icon'] = $parent[3];
    $term['field_status_icon'][LANGUAGE_NONE][0]['bundle'] = $parent[4];

    $status = taxonomy_term_save((object) $term);
  }
  $context['message'] = t('@operation', array('@operation' => $operation));

}

/**
 * BatchAPI callback. Create Services/Category Terms.
 */
function _ntxuva_create_categories($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  // Get the vocabulary ID.
  $vid = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = 'category'")->fetchField();

  // Define the terms.
  $terms[0] = array(
    'Camião não recolheu o contentor',
    'Contentor por recolher',
    '010',
    'contentor',
    '#8B0000',
    'remove',
    'ntxuva-font',
  );
  $terms[1] = array(
    'Contentor a Arder',
    'Contentor incendiado',
    '011',
    'contentor,fogo',
    '#5F9EA0',
    'fire',
    'ntxuva-font',
  );
  $terms[2] = array(
    'Lixo fora do contentor',
    'Lixo fora do contentor',
    '012',
    'lixo',
    '#F5F5DC',
    'bug',
    'ntxuva-font',
  );
  $terms[3] = array(
    'Tchova não passou',
    'Tchova recolheu o lixo',
    '013',
    'recolha',
    '#006400',
    'truck',
    'ntxuva-font',
  );
  $terms[4] = array(
    'Lixeira informal',
    'Tchova recolheu o lixo',
    '014',
    'lixo,lixeira',
    '#006400',
    'spam',
    'ntxuva-font',
  );

  foreach ($terms as $parent) {
    // Create the parent term.
    $term['vid'] = $vid;

    $term['name'] = $parent[0];
    $term['description'] = $parent[1];
    $term['field_category_id'][LANGUAGE_NONE][0]['value'] = $parent[2];
    $term['field_hash'][LANGUAGE_NONE][0]['value'] = $parent[3];
    $term['field_category_hex'][LANGUAGE_NONE][0]['rgb'] = $parent[4];
    $term['field_category_icon'][LANGUAGE_NONE][0]['icon'] = $parent[5];
    $term['field_category_icon'][LANGUAGE_NONE][0]['bundle'] = $parent[6];

    $status = taxonomy_term_save((object) $term);

  }

}


/**
 * BatchAPI callback. Create Reports.
 */
function _ntxuva_create_reports($operation, &$context) {

  $nodes[0] = array(
    'Contentor a Arder',
    'Lorem Ipsum Lorem ipsum dolor sit amet, consectetur ing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,  quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo',
    '-25.974482370893412',
    '32.5734007358551',
    'Avenida 25 de Setembro,  Cidade de Maputo',
    'jjnf@ntxuva.org',
    'Contentor a Arder',
    'Novos',
    'IMG_20141127_090709',
  );

  $nodes[1] = array(
    'Lixo fora do contentor',
    'Lorem Ipsum Lorem ipsum dolor sit amet, consectetur ing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,  quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo',
    '-25.964759700537538',
    '32.582863569259644',
    'Avenida Emilia Dausse,  Cidade de Maputo',
    'jjnf@ntxuva.org',
    'Lixo fora do contentor',
    'Novos',
    'IMG_20141127_090709',
  );

  $nodes[2] = array(
    'Camião não recolheu o contentor',
    'Lorem Ipsum Lorem ipsum dolor sit amet, consectetur ing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,  quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo',
    '-25.933974947537052',
    '32.57094383239746',
    'Rua Augusto Macamo,  Cidade de Maputo',
    'jjnf@ntxuva.org',
    'Camião não recolheu o contentor',
    'Resolvidos',
    'IMG_20141127_090709',
  );

  $nodes[3] = array(
    'Tchova não passou',
    'Lorem Ipsum Lorem ipsum dolor sit amet, consectetur ing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,  quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo',
    '-25.935436354857025',
    '32.59012699127197',
    'Rua Primeiro de Maio,  Cidade de Maputo',
    'jjnf@ntxuva.org',
    'Tchova não passou',
    'Em progresso',
    'IMG_20141127_090709',
  );

  $nodes[4] = array(
    'Camião não recolheu o contentor',
    'Lorem Ipsum Lorem ipsum dolor sit amet, consectetur ing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,  quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo',
    '-25.955770659645914',
    '32.604310512542725',
    'Avenida Julius Nyerere,  Cidade de Maputo',
    'jjnf@ntxuva.org',
    'Camião não recolheu o contentor',
    'Arquivados',
    'IMG_20141127_090709',
  );

  $nodes[5] = array(
    'Contentor a Arder',
    'Lorem Ipsum Lorem ipsum dolor sit amet, consectetur ing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,  quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo',
    '-25.968147294275596',
    '32.59011626243591',
    'Avenida Agostinho Neto,  Cidade de Maputo',
    'jjnf@ntxuva.org',
    'Contentor a Arder',
    'Resolvidos',
    'IMG_20141127_090709',
  );

  foreach ($nodes as $node_data) {
    // Create a new node object:
    $node = new stdClass();
    // Or page, or whatever content type you like:
    $node->type = "report";

    node_object_prepare($node);

    $nid = db_query("SELECT nid FROM {node} ORDER BY nid DESC LIMIT 1")->fetchField();
    $nid++;

    $node->title = $node_data[0];
    $node->language = LANGUAGE_NONE;

    $node->uid = 1;
    $node->nid = $nid;
    $node->language = LANGUAGE_NONE;
    $node->body[$node->language][0]['value'] = $node_data[1];
    $node->body[$node->language][0]['format'] = 'filtered_html';
    $node->field_geo[$node->language][0]['lat'] = $node_data[2];
    $node->field_geo[$node->language][0]['lng'] = $node_data[3];
    $node->field_address[$node->language][0]['value'] = $node_data[4];
    $node->field_e_mail[$node->language][0]['value'] = $node_data[5];
    $node->field_category[$node->language][0]['tid'] = ntxuva_get_term_id($node_data[6]);
    $node->field_status[$node->language][0]['tid'] = ntxuva_get_term_id($node_data[7]);
    $node->is_new = TRUE;
    $node->promote = 0;
    $filename = 'image_' . $node_data[8] . '.jpg';

    $image = file_get_contents('profiles/ntxuva/themes/mopa/images/' . $node_data[8] . '.jpg');
    $file = file_save_data($image, 'public://' . $filename, FILE_EXISTS_RENAME);
    $node->field_image = array(LANGUAGE_NONE => array('0' => (array) $file));

    if ($node = node_submit($node)) {
      node_save($node);
      // drupal_set_message(t('Created example node "%node."', array('%node' => $node->title)));
      if ($node->nid == 1) {
        variable_set('node_uuid', $node->uuid);
      }
    }
  }
  $context['message'] = t('@operation', array('@operation' => $operation));

}

/**
 * BatchAPI callback. Create Specification and About Pages.
 */
function _ntxuva_create_pages($operation, &$context) {
  global $base_url;
  // Now creating articles:
  $nodes[0] = array(
    'Open311',
    '<p> <img src="/profiles/ntxuva/themes/mopa/images/open311georeportv2-type1.png" alt="Open311 Logo" style="width:300px; margin: 0 0 0 10px; height:114px;float:right"> Open311 is a form of technology that provides open channels of communication for issues that concern public space and public services. Primarily, Open311 refers to a standardized protocol for location-based collaborative issue-tracking. </p> <p> By offering free web API access to an existing 311 service, Open311 is an evolution of the phone-based 311 systems that many cities in North America offer. [taken from <a href="http://open311.org/learn/"> Open311 Learn </a>] </p> <p> Ntxuva-Mopa comes with a built-in GeoReport Server. See how it works: </p> <h3>Services</h3> <table class="spec-table"> <tbody> <tr> <th scope="row"> Purpose </th> <td> Provide a list of acceptable 311 service request types and their associated service codes. These request types can be unique to the city/jurisdiction. </td> </tr> <tr> <th scope="row"> URL </th> <td><a href="' . $base_url . '/georeport/v2/services.xml">' . $base_url . '/georeport/v2/services.[format]</a></td> </tr> <tr> <th scope="row"> Sample URL </th> <td> <a href="' . $base_url . '/georeport/v2/services.xml"> ' . $base_url . '/georeport/v2/services.xml </a> </td> </tr> <tr> <th scope="row"> Formats </th> <td> XML / JSON </td> </tr> <tr> <th scope="row"> HTTP Method </th> <td> GET </td> </tr> <tr> <th scope="row"> Requires API Key </th> <td> No </td> </tr> </tbody> </table> <h3> Requests </h3> <table class="spec-table"> <tbody> <tr> <th scope="row"> Purpose </th> <td> Query the current status of multiple requests </td> </tr> <tr> <th scope="row"> URL </th> <td> <a href="' . $base_url . '/georeport/v2/requests.json"> ' . $base_url . '/georeport/v2/requests.[format] </a> </td> </tr> <tr> <th scope="row"> Sample URL </th> <td> <a href="' . $base_url . '/georeport/v2/requests.json?start_date=' . date("Y-n-j") . '"> ' . $base_url . '/georeport/v2/requests.json?start_date=' . date("Y-n-j") . '... </a> </td> </tr> <tr> <th scope="row"> Formats </th> <td> XML, JSON </td> </tr> <tr> <th scope="row"> HTTP Method </th> <td> GET </td> </tr> <tr> <th scope="row"> Requires API Key </th> <td> No </td> </tr> </tbody> </table> <h4> Optionale Parameter </h4> <table class="spec-table arguments-table"> <tbody> <tr> <th> Field Name </th> <th class="spec-description"> Description </th> <th class="spec-requirements"> Notes &amp; Requirements </th> </tr> <tr> <td class="field"> <dl> <dt> service_code <br/> </dt> </dl> </td> <td> Specify the service type by calling the unique ID of the service_code. </td> <td> This defaults to all service codes when not declared; can be declared multiple times, comma delimited </td> </tr> <tr> <td class="field"> <dl> <dt> start_date <br/> </dt> </dl> </td> <td> Earliest datetime to include in search. When provided with end_date, allows one to search for requests which have a requested_datetime that matches a given range, but may not span more than 90 days. </td> <td> When not specified, the range defaults to most recent 90 days. Must use w3 format, eg 2010-01-01T00:00:00Z. </td> </tr> <tr> <td class="field"> <dl> <dt> end_date <br/> </dt> </dl> </td> <td> Latest datetime to include in search. When provided with start_date, allows one to search for requests which have a requested_datetime that matches a given range, but may not span more than 90 days. </td> <td> When not specified, the range defaults to most recent 90 days. Must use w3 format, eg 2010-01-01T00:00:00Z. </td> </tr> <tr> <td class="field"> <dl> <dt> status <br/> </dt> </dl> </td> <td> Allows one to search for requests which have a specific status. This defaults to all statuses; can be declared multiple times, comma delimited; </td> <td> Options: <span class="strict-value"> open </span> , <span class="strict-value"> closed </span> </td> </tr> </tbody> </table> <h3> Single Request </h3> <table class="spec-table"> <tbody> <tr> <th scope="row"> Purpose </th> <td> Query the current status of an individual request </td> </tr> <tr> <th scope="row"> URL </th> <td> <a href="' . $base_url . '/georeport/v2/requests/2.xml"> ' . $base_url . '/georeport/v2/request/#ID.[format] </a> </td> </tr> <tr> <th scope="row"> Sample URL </th> <td><a href="' . $base_url . '/georeport/v2/requests/' . variable_get('node_uuid') . '.json">' . $base_url . '/georeport/v2/requests/' . variable_get('node_uuid') . '.json</a></td> </tr> <tr> <th scope="row"> Formats </th> <td> XML, JSON </td> </tr> <tr> <th scope="row"> HTTP Method </th> <td> GET </td> </tr> <tr> <th scope="row"> Requires API Key </th> <td> No </td> </tr> </tbody> </table>',
    'slider_2',
  );

  // Now creating initial report:
  $nodes[1] = array(
    'About this platform',
    '<p>This platform is based on <a href="http://www.ntxuva.org">Ntxuva</a>, a Drupal distribution for public issue reporting or other geobased crowdsourcing.</p><p>Through a 2014 Innovation Grant the World Bank developed the beta-version of a software platform known as Ntxuva that provides visualizations and statistics from citizen provided information about urban services.</p><p>To overcome entry barriers for often marginalized and under-served periurban populations, Ntxuva will manage information from both designated citizen-monitors and spontaneous crowd sourced reports.</p><p>The platform is designed to collect information from citizens via SMS, mobile app, and Web Portal; a voice interface in local languages is foreseen to enhance access by less educated, poorer populations.</p><p>Ntxuva will be piloted in early 2015. Reports tailored to stakeholder needs and preferences will be provided to municipal service managers and governing officials, to firms providing SWM services, and to citizens and civil society organizations. Scale-up and roll-out are planned for 2015-16.</p><p>All service related information is publicly available through an Open Data API compliant with Open311 – a widely known standard for citizen reporting used in more than 60 US and European cities.</p><p>Ntxuva is based on existent Open Source solutions (<a href="http://mark-a-spot.org">mark-a-spot.org</a>, a Drupal distribution for Open311 as well as VoIP Drupal for SMS integration) and its source code is publicly available via Github. The project also promotes engagement among the local software development/innovation community including firms, universities, and independent hackers/programmers.</p>',
    'slider_1',
  );

  foreach ($nodes as $node_data) {
    $node = new stdClass();
    $node->type = "page";
    node_object_prepare($node);
    $nid = db_query("SELECT nid FROM {node} ORDER BY nid DESC LIMIT 1")->fetchField();
    $nid++;

    $node->title = $node_data[0];
    $node->language = LANGUAGE_NONE;
    $node->uid = 1;
    $node->nid = $nid;
    $node->language = LANGUAGE_NONE;
    $node->body[$node->language][0]['value'] = $node_data[1];
    $node->body[$node->language][0]['format'] = 'full_html';

    $node->is_new = TRUE;
    $node->promote = 0;
    $filename = 'image_' . $node_data[2] . '.jpg';

    $image = file_get_contents('profiles/ntxuva/themes/mopa/images/' . $node_data[2] . '.jpg');
    $file = file_save_data($image, 'public://' . $filename, FILE_EXISTS_RENAME);
    $node->field_image = array(LANGUAGE_NONE => array('0' => (array) $file));

    if ($node = node_submit($node)) {
      node_save($node);
      // drupal_set_message(t('Created Page node "%node."', array('%node' => $node->title)));

    }
  }
  $context['message'] = t('@operation', array('@operation' => $operation));

}

/**
 * BatchAPI callback. Building Blocks with enabled modules.
 */
function _ntxuva_build_blocks($operation, &$context) {
  _ntxuva_activate_block('views', 'report_log-report_log', 'content', 'mopa', 'node/*', '1', '5');
  _ntxuva_activate_block('ntxuva_logic', 'taxonomy_category', 'footer', 'mopa', 'map', '1', '0');
  _ntxuva_activate_block('ntxuva_logic', 'taxonomy_status', 'footer', 'mopa', 'map', '1', '0');
  _ntxuva_activate_block('ntxuva_logic', 'ntxuva_map', 'sidebar_second', 'mopa', 'map', '1', '0');
  _ntxuva_activate_block('system', 'navigation', 'sidebar_second', 'mopa', '<front>' . "\n" . 'node/7' . "\n" . 'node/8', '1', '0');
  _ntxuva_activate_block('menu', 'menu-secondary-navigation', 'footer', 'mopa', 'admin' . "\n" . 'admin/*', '0', '0');
  _ntxuva_activate_block('user', 'login', 'sidebar_second', 'mopa', '<front>' . "\n" . 'node/7' . "\n" . 'node/8', '1', '0');
  _ntxuva_activate_block('ntxuva_default_content', 'welcome', 'content', 'mopa', '<front>', '1', '0');
  _ntxuva_activate_block('ntxuva_default_content', 'search_id', 'sidebar_second', 'mopa', '<front>' . "\n" . 'node/7' . "\n" . 'node/8', '1', '0');
  _ntxuva_activate_block('ntxuva_stats', 'ntxuva_stats', 'sidebar_second', 'mopa', '<front>' . "\n" . 'node/7' . "\n" . 'node/8', '1', '0');
  _ntxuva_activate_block('comment', 'recent', 'sidebar_second', 'mopa', '<front>', '1', '0');
  _ntxuva_activate_block('user', 'new', 'sidebar_second', 'mopa', '<front>', '1', '0');
  $context['message'] = t('@operation', array('@operation' => $operation));

}
/**
 * BatchAPI callback. Activate blocks.
 */
function _ntxuva_activate_block($module, $block, $region, $theme, $pages, $visibility, $weight) {
  // drupal_set_message("Activating block $module:$block\n");
  db_merge('block')
    ->key(array('theme' => $theme, 'delta' => $block, 'module' => $module))
    ->fields(array(
      'region' => ($region == BLOCK_REGION_NONE ? '' : $region),
      'pages' => $pages,
      'status' => (int) ($region != BLOCK_REGION_NONE),
      'visibility' => $visibility,
      'weight' => $weight,
    ))
    ->execute();
  if($block == "report_log-report_log"){
    $query = db_insert('block_node_type')->fields(array('type', 'module', 'delta'));
    $query->values(
      array(
        'type' => 'report',
        'module' => 'views',
        'delta' => 'report_log-report_log',
      )
    );
    $query->execute();
  }
}
/**
 * BatchAPI callback. Delete dummies after installation.
 *
 */
function _ntxuva_delete_dummies($operation, &$context) {
  // Get the vocabulary ID.
  $vid = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = 'status'")->fetchField();
  $taxonomies = taxonomy_get_tree($vid, $parent = 0, $max_depth = 1, $load_entities = TRUE);

  foreach ($taxonomies as $term) {
    if ($term->name == 'dummy') {
      taxonomy_term_delete($term->tid);
    }
  }
  $context['message'] = t('@operation', array('@operation' => $operation));
}

/**
 * BatchAPI callback. Enable module callback
 *
 */
function _ntxuva_enable_module($module, $module_name, &$context) {
  // Increase maximum function nesting level to prevent install errors.
  $max_nesting_level = ini_get('xdebug.max_nesting_level');
  if ($max_nesting_level > 0 && $max_nesting_level <= '200') {
    ini_set('xdebug.max_nesting_level', 200);
  }
  ini_set('max_execution_time', '300');
  module_enable(array($module), FALSE);
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}

/**
 * BatchAPI callback. Flash all cashes.
 *
 */
function _ntxuva_flush_cashes(&$context) {
  // Clear the caches in case the data has been updated.
  drupal_flush_all_caches();;
  $context['message'] = st('Flushed cashes.');
}
