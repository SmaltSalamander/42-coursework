#!/bin/sh

if [ ! -d /var/lib/mysql/$WP_DB_NAME ]; then
	echo -e "Installing Database\n"
	mariadb-install-db --user=mysql --ldata=/var/lib/mysql
	#  --bootstrap         Used by mysql installation scripts.
	sed -i "s/WP_ID/$WP_ID/g" /tmp/initsql.sql
	sed -i "s/WP_PW/$WP_PW/g" /tmp/initsql.sql
	sed -i "s/WP_DB_NAME/$WP_DB_NAME/g" /tmp/initsql.sql
	sed -i "s/MYSQL_ROOT_PASSWORD/$MYSQL_ROOT_PASSWORD/g" /tmp/initsql.sql

	# exec /usr/bin/mysqld --user=mysql --init-file=/tmp/initsql.sql
	# /usr/bin/mysqld --user=mysql
	# mariadb --user=mysql mysql < /tmp/initsql.sql
	# mariadb -u $WP_ID --password=$WP_PW $WP_DB_NAME < /tmp/wp.sql
	# exec mysqld --user=mysql
	exec mysqld --user=mysql --init-file=/tmp/initsql.sql
	# mariadb -u $WP_ID --password=$WP_PW $WP_DB_NAME < /tmp/wp.sql
	# exec mysqld --user=$WP_ID --password=$WP_PW --init-file=/tmp/wp.sql

	# --datadir=/var/lib/mysql 
else
	echo -e "Running smoothly\n"
	exec mysqld --user=mysql
fi

# --protocol=tcp for connection ?