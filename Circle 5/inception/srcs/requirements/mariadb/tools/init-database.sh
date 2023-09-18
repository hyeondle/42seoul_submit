#!/bin/bash

MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}
MYSQL_DATABASE=${MYSQL_DATABASE}
MYSQL_USER=${MYSQL_USER}
MYSQL_PASSWORD=${MYSQL_PASSWORD}

mkdir -p /var/run/mysqld/
chown -R mysql:mysql /var/run/mysqld/
chown -R mysql:mysql /var/lib/mysql/

if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql/
    mysqld &
    MYSQL_PID=$!

sleep 10

mysqladmin -u root password "$MYSQL_ROOT_PASSWORD"

mysql -u root <<-EOSQL
CREATE DATABASE $MYSQL_DATABASE;
CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOSQL
    kill -TERM $MYSQL_PID
    wait $MYSQL_PID
fi

exec mysqld
