#!/bin/sh
mysql_install_db --user=root
/usr/bin/mysqld --user=root --bootstrap < /tmp/initsql.sql
/usr/bin/mysqld --user=root