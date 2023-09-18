#!/bin/bash

until mysql -h mariadb -u $MYSQL_USER -p$MYSQL_PASSWORD -e "show databases;"; do
    echo "Waiting for database connection..."
    sleep 5
done
echo "connect success"
if [ ! -f /var/www/html/wp-config.php ]; then
    wp core download --path=/var/www/html --allow-root
    wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb:3306 --path=/var/www/html --allow-root
    wp core install --url=$DOMAIN_NAME --title="Hyeondle Blog" --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --path=/var/www/html --allow-root
    wp user create $WP_USER $WP_USER_EMAIL --role=editor --user_pass=$WP_USER_PASSWORD --path=/var/www/html --allow-root
fi
mkdir -p /run/php/
chown www-data:www-data /run/php/
php-fpm7.4 -F
