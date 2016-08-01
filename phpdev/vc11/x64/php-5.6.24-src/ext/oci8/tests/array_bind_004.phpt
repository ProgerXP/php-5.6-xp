--TEST--
oci_bind_array_by_name() and invalid values 4
--SKIPIF--
<?php
$target_dbs = array('oracledb' => true, 'timesten' => false);  // test runs on these DBs
require(dirname(__FILE__).'/skipif.inc');
?> 
--FILE--
<?php

require dirname(__FILE__).'/connect.inc';

$drop = "DROP table bind_test";
$statement = oci_parse($c, $drop);
@oci_execute($statement);

$create = "CREATE table bind_test(name DATE)";
$statement = oci_parse($c, $create);
oci_execute($statement);

$create_pkg = "
CREATE OR REPLACE PACKAGE ARRAY_BIND_004_PKG AS 
  TYPE ARRTYPE IS TABLE OF DATE INDEX BY BINARY_INTEGER; 
  PROCEDURE iobind(c1 IN OUT ARRTYPE); 
END ARRAY_BIND_004_PKG;";
$statement = oci_parse($c, $create_pkg);
oci_execute($statement);

$create_pkg_body = "
CREATE OR REPLACE PACKAGE BODY ARRAY_BIND_004_PKG AS 
  CURSOR CUR IS SELECT name FROM bind_test;
  PROCEDURE iobind(c1 IN OUT ARRTYPE) IS
    BEGIN
    FOR i IN 1..5 LOOP
      INSERT INTO bind_test VALUES (c1(i));
    END LOOP;
    IF NOT CUR%ISOPEN THEN
      OPEN CUR;
    END IF;
    FOR i IN REVERSE 1..5 LOOP
      FETCH CUR INTO c1(i);
      IF CUR%NOTFOUND THEN
        CLOSE CUR;
        EXIT;
      END IF;
    END LOOP;
  END iobind;
END ARRAY_BIND_004_PKG;";
$statement = oci_parse($c, $create_pkg_body);
oci_execute($statement);

$statement = oci_parse($c, "BEGIN array_bind_004_pkg.iobind(:c1); END;");

$array = Array();

oci_bind_array_by_name($statement, ":c1", $array, 5, 5, SQLT_ODT);

oci_execute($statement);

var_dump($array);

echo "Done\n";
?>
--EXPECTF--	
Warning: oci_execute(): ORA-01403: %s
ORA-06512: at "SYSTEM.ARRAY_BIND_004_PKG", line %d
ORA-06512: at line %d in %sarray_bind_004.php on line %d
array(0) {
}
Done
