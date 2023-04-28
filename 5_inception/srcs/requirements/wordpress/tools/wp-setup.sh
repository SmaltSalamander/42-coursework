if [ ! -d "/var/www/html/wp-config.php" ];
	then
	cd /var/www/html/
	wp --allow-root core download --path=/var/www/html
	# mkdir -p /var/www/html/wp-content/themes
	wp --allow-root config create \
		--path=/var/www/html \
		--dbname=$WP_DB_NAME \
		--dbuser=$WP_ID --dbpass=$WP_PW --dbhost=$WPDB_HOST
	wp core install \
		--url="https://sbienias.42.fr" \
		--title=inception \
		--admin_name=$WP_ADM_U \
		--admin_password=$WP_ADM_P \
		--admin_email=$WP_ADM_MAIL \
		--path=/var/www/html \
		--skip-email \
		--allow-root
	wp --allow-root user create $WP_ID $WP_MAIL --role=author \
		--user_pass=$WP_PW --path=/var/www/html
	wp --allow-root theme install kadence --activate
fi

# exec "$@"
exec /usr/sbin/php-fpm7 -F