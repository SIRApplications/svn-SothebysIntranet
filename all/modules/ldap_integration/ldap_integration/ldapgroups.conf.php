<?php
// $Id: ldapgroups.conf.php,v 1.9 2007/07/22 20:04:25 kreaper Exp $

// Interesting constants that admins would want to mess with

//   The module automatically decides names for the Drupal roles
// based in the names of the LDAP groups. For example:
//   - LDAP group: Admins => Drupal role: Admins
//   - LDAP group: ou=Underlings,dc=myorg,dc=mytld => Drupal role: Underlings
//   However, if this is not enough, this name mapping can be refined
// by altering this array. Some examples are given.


$GLOBALS['ldap_group_role_mappings'] = array(
//   LDAP group => Drupal role
  
  // make sure the last group->role mapping does NOT have a trailing comma (,)
//  
	'cn=Eastern Region Agents,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Eastern Region Agents',
	'cn=Eastern Region Employees,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Eastern Region Employees',
	'cn=Eastern Region Admins,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Eastern Region Admins',
	//
	'cn=Western Region Agents,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Western Region Agents',
	'cn=Western Region Employees,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Western Region Employees',
	'cn=Western Region Admins,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Western Region Admins',
	//
	'cn=Mountain Region Agents,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Mountain Region Agents',
	'cn=Mountain Region Employees,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Mountain Region Employees',
	'cn=Mountain Region Admins,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'Mountain Region Admins',
	//
	'cn=SIR Agents,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'SIR Agents',
	'cn=SIR Employees,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'SIR Employees',
	'cn=SIR Managers,ou=Security Groups,dc=sirny,dc=ne,dc=nrt' => 'SIR Managers'
//
);

// Note: Uncommenting this function will limit the groups -> roles conversion to ONLY those groups that are 
// specified in the function. 

function ldapgroups_roles_filter($groups) { 
  global $ldap_group_role_mappings; 
  $roles = array(); 
  // this should take the roles array, pass it thru the filters and send a NEW set of roles back the filter 
  foreach ( $groups as $group ) { 
    foreach ($ldap_group_role_mappings as $approved_group => $approved_role) {
       // must strip spaces ?
       $group_stripped = preg_replace('/\s+/', '', $group);
       $approved_group_stripped = preg_replace('/\s+/', '', $approved_group);       
      if (strcasecmp($approved_group_stripped, $group_stripped) == 0) {
        // this role is specified -- grant
	   $roles[] = $approved_role;
      }
    }
  }
  return $roles;
}


?>