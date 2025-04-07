#!/bin/sh

if [! -d /usr/local/mysql/var/mysql]; then
	mariadb-install-db
	rc-service mariadb start

	mariadb -e "CREATE DATABASE IF NOT EXISTS \`${MARIADB_NAME}\`;"
	mariadb -e "USER IF NOT EXISTS \`${MARIADB_USER}\` IDENTIFIED BY \`${MARIADB_PASSWORD}\`;"
	mariadb -e "GRANT ALL PRIVILEGES ON \`${MARIADB_NAME}\`.* TO \`${MARIADB_USER}\`;"
	mariadb -e "FLUSH PRIVILEGES;"

	rc-service mariadb stop
fi

mariadbd-safe