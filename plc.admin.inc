<?php

/**
 * @file
 * Main checklist functions available here.
 */

/**
 * Main callback function().
 *
 * @return type
 */
function _plc_summary() {
  $plc_modules = _plc_disable_module_list();

  $plc_data = array();
  $plc_data[] = _plc_get_watchdog_count();
  $data_output = _plc_data_summary($plc_data);

  $variable_output = _plc_system_variables_list();

  $output = $plc_modules . $data_output . $variable_output;
  return $output;
}

/**
 * Function will hold module list to be disabled
 *
 * @return array
 */
function _plc_disable_module_list() {
  $plc_modules = array();
  $plc_modules = array(
    'dblog' => array('data' => array(
        t('Watchdog Module'),
        t('Watchdog Module'),
      ),
    ),
    'devel' => array('data' => array(
        t('Devel'),
        t('Development Module'),
      ),
    ),
    'coder' => array('data' => array(
        t('Coder'),
        t('Coding Standard and review Module'),
      ),
    ),
    'views_ui' => array('data' => array(
        t('Views UI'),
        t('UI to build Views'),
      ),
    ),
    'feeds_ui' => array('data' => array(
        t('Feeds UI'),
        t('UI to build feeds'),
      ),
    ),
    'field_ui' => array('data' => array(
        t('Field UI'),
        t('UI to manage field'),
      ),
    ),
    'queue_ui' => array('data' => array(
        t('Queue UI'),
        t('UI to manage Queue'),
      ),
    ),
    'context_ui' => array('data' => array(
        t('Context UI'),
        t('UI to manage Context'),
      ),
    ),
  );

  foreach ($plc_modules as $k => $v) {
    if (module_exists($k)) {
      $plc_modules[$k]['data'][2] = t('!url', array('!url' => l(t('Enabled'), "admin/modules")));
      $plc_modules[$k]['class'] = array('error');
    }
    else {
      $plc_modules[$k]['data'][2] = t('Disabled');
      $plc_modules[$k]['class'] = array('ok');
    }
  }

  $header = array(
    'Module Name',
    'Description',
    'Status',
  );
  $table_attributes = array('id' => 'plc');

  $output = "<h2>Module need to be disabled: </h2>";
  $output .= theme('table', array('header' => $header, 'rows' => $plc_modules, 'attributes' => $table_attributes));
  return $output;
}

/**
 *
 * @return type count
 */
function _plc_get_watchdog_count() {
  $count_query = db_select('watchdog', 'w')->fields('w');
  $result = $count_query->execute()->rowCount();
  if (count($result) > 0) $watchdog_msg = t("Please clear the !url, current count : @result",
    array('!url' => l(t('watchdog'), "admin/reports/dblog"), '@result' => $result)
  );
  else {
    $watchdog_msg = t("Watchdog is empty.");
  }
  return array('Watchdog', $watchdog_msg);
}

/**
 *
 * @param type $plc_data
 *
 * @return type
 */
function _plc_data_summary($plc_data) {
  $header = array(
    'Data',
    'Description',
  );
  $output = "<h2>Data Summary: </h2>";
  $output .= theme('table', array('header' => $header, 'rows' => $plc_data));
  return $output;
}

/**
 *
 * @global type $conf
 * @global type $cookie_domain
 * @global type $update_free_access
 *
 * @return type
 */
function _plc_system_variables_list() {
  global $conf;
  global $cookie_domain;
  global $update_free_access;

  $plc_variables = array();
  $plc_variables = array(
    'timezone' => array(
      'data' => array('Timezone', $conf['date_default_timezone']),
    ),
    'site_mail' => array(
      'data' => array('Site email address', $conf['site_mail']),
    ),
    'site_name' => array(
      'data' => array('Site name', $conf['site_name']),
    ),
    'clean_url' => array(
      'data' => array('clean_url', $conf['clean_url']),
    ),
    'brightcove_read_api_key' => array(
      'data' => array('Brighcove Read API Key', $conf['brightcove_read_api_key']),
    ),
    'brightcove_write_api_key' => array(
      'data' => array('Brighcove Write API Key', $conf['brightcove_write_api_key']),
    ),
    'tealium_account' => array(
      'data' => array('tealium_account', $conf['tealium_account']),
    ),
    'tealium_profile' => array(
      'data' => array('tealium_profile', $conf['tealium_profile']),
    ),
    'tealium_environment' => array(
      'data' => array('tealium_environment', $conf['tealium_environment']),
    ),
    'tealium_utag_async' => array(
      'data' => array('tealium_utag_async', $conf['tealium_utag_async']),
    ),
    'cookie_domain' => array(
      'data' => array('cookie_domain', $cookie_domain),
    ),
    'update_free_access' => array(
      'data' => array('update_free_access', $update_free_access),
    ),
    'file_public_path' => array(
      'data' => array('file_public_path', $conf['file_public_path']),
    ),
    'apachesolr_default_environment' => array(
      'data' => array('apachesolr_default_environment', $conf['apachesolr_default_environment']),
    ),
  );

  $plc_performance = array();
  $plc_performance = array(
    'preprocess_css' => array(
      'data' => array('CSS Aggregation', $conf['preprocess_css'], t('TRUE')),
    ),
    'preprocess_js' => array(
      'data' => array('JS Aggregation', $conf['preprocess_js'], t('TRUE')),
    ),
    'error_level' => array(
      'data' => array('Error Level', $conf['error_level'], 0),
    ),
    'cache' => array(
      'data' => array('cache', $conf['cache'], 1),
    ),
    'block_cache' => array(
      'data' => array('block_cache', $conf['block_cache'], 1),
    ),
    'cache_lifetime' => array(
      'data' => array('cache_lifetime', $conf['cache_lifetime'], 900),
    ),
    'page_cache_maximum_age' => array(
      'data' => array('page_cache_maximum_age', $conf['page_cache_maximum_age'], 900),
    ),
    'page_compression' => array(
      'data' => array('page_compression', $conf['page_compression'], 1),
    ),
    'cdn_status' => array(
      'data' => array('CDN Status', $conf['cdn_status'], 1),
    ),
    'fast_404_path_check' => array(
      'data' => array('Fast 404 Path Check', $conf['fast_404_path_check'], t('TRUE')),
    ),
    'redirect_page_cache' => array(
      'data' => array('Redirect Page Cache', $conf['redirect_page_cache'], t('TRUE')),
    ),
    'page_cache_invoke_hooks' => array(
      'data' => array('page_cache_invoke_hooks', $conf['page_cache_invoke_hooks'], t('TRUE')),
    ),
    'memcache_servers' => array(
      'data' => array('memcache_servers', $conf['memcache_servers'], '-'),
    ),
    'cache_backends' => array(
      'data' => array('MemCache cache_backends', implode('<br/>', $conf['cache_backends']), '-'),
    ),
    'cache_default_class' => array(
      'data' => array('MemCache cache_default_class', $conf['cache_default_class'], '-'),
    ),
    'cache_class_cache_form' => array(
      'data' => array('MemCache cache_class_cache_form', $conf['cache_class_cache_form'], '-'),
    ),
    'cache_class_cache_page' => array(
      'data' => array('MemCache Cookie: cache_class_cache_page', $conf['cache_class_cache_page'], '-'),
    ),
    'reverse_proxy' => array(
      'data' => array('Varnish reverse_proxy', $conf['reverse_proxy'], t('TRUE')),
    ),
  );

  $plc_variables = _plc_table_row_class($plc_variables);
  $plc_performance = _plc_table_row_class($plc_performance);

  $plc_variables = _plc_not_configured($plc_variables);
  $plc_performance = _plc_not_configured($plc_performance);

  $header1 = array(
    'Variable',
    'Value',
  );

  $header2 = array(
    'Variable',
    'Value',
    'Recommended settings',
  );
  $table_attributes = array('id' => 'plc');

  $output = "<h2>System Variables: </h2>";
  $output .= theme('table', array('header' => $header1, 'rows' => $plc_variables,
      'attributes' => $table_attributes,
    ));
  $output .= "<h2>Performance and scalability configuration: </h2>";
  $output .= theme('table', array('header' => $header2, 'rows' => $plc_performance,
      'attributes' => $table_attributes,
    ));

  return $output;
}

/**
 *
 * @param type $var
 *
 * @return type
 */
function _plc_not_configured($var) {
  foreach ($var as $k => $v) {
    if ($v['data'][1] === "" || $v['data'][1] == NULL) {
      $var[$k]['data'][1] = t('Not Configured');
    }
    elseif ($v['data'][1] !== 0 && $v['data'][1] === FALSE) {
      $var[$k]['data'][1] = t('FALSE');
    }
    elseif ($v['data'][1] !== 1 && $v['data'][1] === TRUE) {
      $var[$k]['data'][1] = t('TRUE');
    }
  }

  return $var;
}

/**
 *
 * @param type $var
 *
 * @return string
 */
function _plc_table_row_class($var) {
  foreach ($var as $k => $v) {
    if ($v['data'][1] === "" || $v['data'][1] == NULL) {
      $var[$k]['class'] = array('error');
    }
    elseif (isset($v['data'][2]) && $v['data'][2] === '-') {
      $var[$k]['class'] = array('info');
    }
    elseif (isset($v['data'][2]) && $v['data'][1] != $v['data'][2]) {
      $var[$k]['class'] = array('warning');
    }
    else {
      $var[$k]['class'] = array('ok');
    }
  }

  return $var;
}

