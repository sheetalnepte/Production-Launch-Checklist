<?php

/**
 * @file
 * Main checklist functions available here.
 */

/**
 * Main callback function().
 *
 * @return string
 *   Returns output for the page.
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
 * Function will hold module list to be disabled.
 *
 * @return string
 *    Returns list of modules.
 */
function _plc_disable_module_list() {
  $plc_modules = _plc_get_recommend_disable_module();

  foreach ($plc_modules as $k => $v) {
    if (module_exists($k)) {
      $plc_modules[$k]['data']['#path'] = t('!url', array('!url' => l(t('Enabled'), "admin/modules")));
      $plc_modules[$k]['class'] = array('error');
    }
    else {
      $plc_modules[$k]['data']['#path'] = t('Disabled');
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
  $output .= theme('table', array(
    'header' => $header,
    'rows' => $plc_modules,
    'attributes' => $table_attributes,
    ));
  return $output;
}

/**
 * Function will check for the errors in db.
 *
 * @return array count
 *    Returns watchdog count.
 */
function _plc_get_watchdog_count() {
  $count_query = db_select('watchdog', 'w')->fields('w');
  $result = $count_query->execute()->rowCount();
  if (count($result) > 0) {
    $watchdog_msg = t("Please clear the !url, current count : @result", array(
      '!url' => l(t('watchdog'), "admin/reports/dblog"),
      '@result' => $result,
      ));
  }
  else {
    $watchdog_msg = t("Watchdog is empty.");
  }
  return array('Watchdog', $watchdog_msg);
}

/**
 * Outputs data summary in table format.
 *
 * @param array $plc_data
 *    Contains processed data.
 *
 * @return string
 *    Returns output for the page.
 */
function _plc_data_summary(array $plc_data) {
  $header = array(
    'Data',
    'Description',
  );
  $output = "<h2>Data Summary: </h2>";
  $output .= theme('table', array('header' => $header, 'rows' => $plc_data));
  return $output;
}

/**
 * Reads system configuration and recommends the settings.
 *
 * @return string
 *   Returns output for the page.
 */
function _plc_system_variables_list() {
  $plc_variables = _plc_get_environment_variables();
  $plc_variables = _plc_table_row_class($plc_variables);
  $plc_variables = _plc_not_configured($plc_variables);

  $plc_performance = _plc_get_performance_variables();
  $plc_performance = _plc_table_row_class($plc_performance);
  $plc_performance = _plc_not_configured($plc_performance);

  $header1 = array(
    'Variable',
    'Value',
    'Configure',
  );

  $header2 = array(
    'Variable',
    'Value',
    'Recommended settings',
    'Configure',
  );
  $table_attributes = array('id' => 'plc');

  $output = "<h2>System Variables: </h2>";
  $output .= theme('table', array(
      'header' => $header1,
      'rows' => $plc_variables,
      'attributes' => $table_attributes,
    ));
  $output .= "<h2>Performance and scalability configuration: </h2>";
  $output .= theme('table', array(
      'header' => $header2,
      'rows' => $plc_performance,
      'attributes' => $table_attributes,
    ));

  return $output;
}

/**
 * Displays value based of configuration.
 *
 * @param array $var
 *   Contains the environament variables data.
 *
 * @return array
 *   Returns array with appropriate values.
 */
function _plc_not_configured(array $var) {
  foreach ($var as $k => $v) {
    if ($v['data']['#value'] !== 0 && $v['data']['#value'] === FALSE) {
      $var[$k]['data']['#value'] = t('FALSE');
    }
    elseif ($v['data']['#value'] !== 1 && $v['data']['#value'] === TRUE) {
      $var[$k]['data']['#value'] = t('TRUE');
    }
    elseif ($v['data']['#value'] === "" || $v['data']['#value'] == NULL) {
      $var[$k]['data']['#value'] = t('Not Configured');
    }
  }

  return $var;
}

/**
 * Apply CSS class based on the values.
 *
 * @param array $var
 *   Contains the environament variables data.
 *
 * @return array
 *   Returns array with appropriate CSS class.
 */
function _plc_table_row_class(array $var) {
  foreach ($var as $k => $v) {
    if ($v['data']['#value'] === "" || $v['data']['#value'] == NULL) {
      $var[$k]['class'] = array('error');
    }
    elseif (isset($v['data']['#recommend']) && $v['data']['#recommend'] === '-') {
      $var[$k]['class'] = array('info');
    }
    elseif (isset($v['data']['#recommend']) && $v['data']['#value'] != $v['data']['#recommend']) {
      $var[$k]['class'] = array('warning');
    }
    else {
      $var[$k]['class'] = array('ok');
    }
  }

  return $var;
}
