<?php

/**
 * @file
 * File contains construction of arrays.
 */

/**
 * List of modules to be disabled.
 *
 * @return array
 *    Returns module list.
 */
function _plc_get_recommend_disable_module() {
  $plc_modules = array(
    'dblog' => array(
      'data' => array(
        '#title' => t('Watchdog Module'),
        '#description' => t('Watchdog Module'),
      ),
    ),
    'devel' => array(
      'data' => array(
        '#title' => t('Devel'),
        '#description' => t('Development Module'),
      ),
    ),
    'coder' => array(
      'data' => array(
        '#title' => t('Coder'),
        '#description' => t('Coding Standard and review Module'),
      ),
    ),
    'views_ui' => array(
      'data' => array(
        '#title' => t('Views UI'),
        '#description' => t('UI to build Views'),
      ),
    ),
    'feeds_ui' => array(
      'data' => array(
        '#title' => t('Feeds UI'),
        '#description' => t('UI to build feeds'),
      ),
    ),
    'field_ui' => array(
      'data' => array(
        '#title' => t('Field UI'),
        '#description' => t('UI to manage field'),
      ),
    ),
    'queue_ui' => array(
      'data' => array(
        '#title' => t('Queue UI'),
        '#description' => t('UI to manage Queue'),
      ),
    ),
    'context_ui' => array(
      'data' => array(
        '#title' => t('Context UI'),
        '#description' => t('UI to manage Context'),
      ),
    ),
  );

  return $plc_modules;
}

/**
 * Constructs environment variable array.
 *
 * @global type $conf
 * @global type $cookie_domain
 * @global type $update_free_access
 *
 * @return array
 *    Returns variable list.
 */
function _plc_get_environment_variables() {
  global $conf;
  global $cookie_domain;
  global $update_free_access;

  $plc_variables = array(
    'timezone' => array(
      'data' => array(
        '#title' => 'Timezone',
        '#value' => $conf['date_default_timezone'],
        '#path' => l(t('configure'), 'admin/config/regional/settings'),
      ),
    ),
    'site_mail' => array(
      'data' => array(
        '#title' => 'Site email address',
        '#value' => $conf['site_mail'],
        '#path' => l(t('configure'), 'admin/config/system/site-information'),
      ),
    ),
    'site_name' => array(
      'data' => array(
        '#title' => 'Site name',
        '#value' => $conf['site_name'],
        '#path' => l(t('configure'), 'admin/config/system/site-information'),
      ),
    ),
    'clean_url' => array(
      'data' => array(
        '#title' => 'clean_url',
        '#value' => $conf['clean_url'],
        '#path' => l(t('configure'), 'admin/config/search/clean-urls'),
      ),
    ),
    'brightcove_read_api_key' => array(
      'data' => array(
        '#title' => 'Brighcove Read API Key',
        '#value' => $conf['brightcove_read_api_key'],
        '#path' => l(t('configure'), 'admin/config/media/brightcove'),
      ),
    ),
    'brightcove_write_api_key' => array(
      'data' => array(
        '#title' => 'Brighcove Write API Key',
        '#value' => $conf['brightcove_write_api_key'],
        '#path' => l(t('configure'), 'admin/config/media/brightcove'),
      ),
    ),
    'tealium_account' => array(
      'data' => array(
        '#title' => 'tealium_account',
        '#value' => $conf['tealium_account'],
        '#path' => l(t('configure'), 'admin/config/services/tealium'),
      ),
    ),
    'tealium_profile' => array(
      'data' => array(
        '#title' => 'tealium_profile',
        '#value' => $conf['tealium_profile'],
        '#path' => l(t('configure'), 'admin/config/services/tealium'),
      ),
    ),
    'tealium_environment' => array(
      'data' => array(
        '#title' => 'tealium_environment',
        '#value' => $conf['tealium_environment'],
        '#path' => l(t('configure'), 'admin/config/services/tealium'),
      ),
    ),
    'tealium_utag_async' => array(
      'data' => array(
        '#title' => 'tealium_utag_async',
        '#value' => $conf['tealium_utag_async'],
        '#path' => l(t('configure'), 'admin/config/services/tealium'),
      ),
    ),
    'cookie_domain' => array(
      'data' => array(
        '#title' => 'cookie_domain',
        '#value' => $cookie_domain,
        '#path' => 'settings.php',
      ),
    ),
    'update_free_access' => array(
      'data' => array(
        '#title' => 'update_free_access',
        '#value' => $update_free_access,
        '#path' => 'settings.php',
      ),
    ),
    'file_public_path' => array(
      'data' => array(
        '#title' => 'file_public_path',
        '#value' => $conf['file_public_path'],
        '#path' => l(t('configure'), 'admin/config/media/file-system'),
      ),
    ),
    'apachesolr_default_environment' => array(
      'data' => array(
        '#title' => 'apachesolr_default_environment',
        '#value' => $conf['apachesolr_default_environment'],
        '#path' => l(t('configure'), 'admin/config/search/apachesolr/settings'),
      ),
    ),
  );

  return $plc_variables;
}

/**
 * Constructs performance variable array.
 *
 * @global type $conf
 *
 * @return array
 *    Returns varibale list.
 */
function _plc_get_performance_variables() {
  global $conf;
  $plc_performance = array();
  $plc_performance = array(
    'preprocess_css' => array(
      'data' => array(
        '#title' => 'CSS Aggregation',
        '#value' => $conf['preprocess_css'],
        '#recommend' => t('TRUE'),
        '#path' => l(t('configure'), 'admin/config/development/performance'),
      ),
    ),
    'preprocess_js' => array(
      'data' => array(
        '#title' => 'JS Aggregation',
        '#value' => $conf['preprocess_js'],
        '#recommend' => t('TRUE'),
        '#path' => l(t('configure'), 'admin/config/development/performance'),
      ),
    ),
    'error_level' => array(
      'data' => array(
        '#title' => 'Error Level',
        '#value' => $conf['error_level'],
        '#recommend' => 0,
        '#path' => l(t('configure'), 'admin/config/development/logging'),
      ),
    ),
    'cache' => array(
      'data' => array(
        '#title' => 'cache',
        '#value' => $conf['cache'],
        '#recommend' => 1,
        '#path' => l(t('configure'), 'admin/config/development/performance'),
      ),
    ),
    'block_cache' => array(
      'data' => array(
        '#title' => 'block_cache',
        '#value' => $conf['block_cache'],
        '#recommend' => 1,
        '#path' => l(t('configure'), 'admin/config/development/performance'),
      ),
    ),
    'cache_lifetime' => array(
      'data' => array(
        '#title' => 'cache_lifetime',
        '#value' => $conf['cache_lifetime'],
        '#recommend' => 900,
        '#path' => l(t('configure'), 'admin/config/development/performance'),
      ),
    ),
    'page_cache_maximum_age' => array(
      'data' => array(
        '#title' => 'page_cache_maximum_age',
        '#value' => $conf['page_cache_maximum_age'],
        '#recommend' => 900,
        '#path' => l(t('configure'), 'admin/config/development/performance'),
      ),
    ),
    'page_compression' => array(
      'data' => array(
        '#title' => 'page_compression',
        '#value' => $conf['page_compression'],
        '#recommend' => 1,
        '#path' => l(t('configure'), 'admin/config/development/performance'),
      ),
    ),
    'cdn_status' => array(
      'data' => array(
        '#title' => 'CDN Status',
        '#value' => $conf['cdn_status'],
        '#recommend' => 1,
        '#path' => l(t('configure'), 'admin/config/development/cdn'),
      ),
    ),
    'fast_404_path_check' => array(
      'data' => array(
        '#title' => 'Fast 404 Path Check',
        '#value' => $conf['fast_404_path_check'],
        '#recommend' => t('TRUE'),
        '#path' => 'settings.php',
      ),
    ),
    'redirect_page_cache' => array(
      'data' => array(
        '#title' => 'Redirect Page Cache',
        '#value' => $conf['redirect_page_cache'],
        '#recommend' => t('TRUE'),
        '#path' => 'settings.php',
      ),
    ),
    'page_cache_invoke_hooks' => array(
      'data' => array(
        '#title' => 'page_cache_invoke_hooks',
        '#value' => $conf['page_cache_invoke_hooks'],
        '#recommend' => t('TRUE'),
        '#path' => 'settings.php',
      ),
    ),
    'memcache_servers' => array(
      'data' => array(
        '#title' => 'memcache_servers',
        '#value' => implode('<br/>', $conf['memcache_servers']),
        '#recommend' => '-',
        '#path' => 'settings.php',
      ),
    ),
    'cache_backends' => array(
      'data' => array(
        '#title' => 'MemCache cache_backends',
        '#value' => implode('<br/>', $conf['cache_backends']),
        '#recommend' => '-',
        '#path' => 'settings.php',
      ),
    ),
    'cache_default_class' => array(
      'data' => array(
        '#title' => 'MemCache cache_default_class',
        '#value' => $conf['cache_default_class'],
        '#recommend' => '-',
        '#path' => 'settings.php',
      ),
    ),
    'cache_class_cache_form' => array(
      'data' => array(
        '#title' => 'MemCache cache_class_cache_form',
        '#value' => $conf['cache_class_cache_form'],
        '#recommend' => '-',
        '#path' => 'settings.php',
      ),
    ),
    'cache_class_cache_page' => array(
      'data' => array(
        '#title' => 'MemCache Cookie: cache_class_cache_page',
        '#value' => $conf['cache_class_cache_page'],
        '#recommend' => '-',
        '#path' => 'settings.php',
      ),
    ),
    'reverse_proxy' => array(
      'data' => array(
        '#title' => 'Varnish reverse_proxy',
        '#value' => $conf['reverse_proxy'],
        '#recommend' => t('TRUE'),
        '#path' => 'settings.php',
      ),
    ),
  );
  return $plc_performance;
}
