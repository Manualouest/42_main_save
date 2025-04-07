#!/bin/sh

if [ ! -f /var/www/html/wp-config.php ]; then

	# Mandatory part
    cd /var/www/html

    if [ ! -f index.php ]; then
        wp.phar core download
    fi

    sleep 1

    wp.phar config create --dbname="$MARIADB_NAME" --dbuser="$WORDPRESS_DB_USER" --dbpass="$WORDPRESS_DB_PASSWORD" --dbhost=mariadb
    wp.phar core install --url="${DOMAIN_NAME}" --title="Inception" --admin_user="$ADMIN_USERNAME" --admin_password="$ADMIN_PASSWORD" --admin_email="$ADMIN_MAIL"
    wp.phar user create $USER_USERNAME $USER_MAIL --role=author --user_pass="$USER_PASSWORD"

    # DEBUG
    wp.phar config set WP_DEBUG true --allow-root
    wp.phar config set WP_DEBUG_log true --allow-root
    wp.phar config set WP_DEBUG_DISPLAY false --allow-root

    # Bonus part -> Redis
    # wp.phar config set WP_REDIS_HOST "redis" --allow-root
    #   wp.phar config set WP_REDIS_PORT 6379 --raw --allow-root
    # wp.phar config set WP_REDIS_DATABASE 0 --allow-root
    # wp.phar config set WP_REDIS_TIMEOUT 1 --allow-root
    # wp.phar config set WP_REDIS_READ_TIMEOUT 1 --allow-root
    #  wp.phar config set WP_REDIS_CLIENT phpredis --allow-root
    # wp.phar config set WP_CACHE true --allow-root
    #  wp.phar config set WP_CACHE_KEY_SALT "${DOMAIN_NAME}" --allow-root

    # wp.phar plugin install redis-cache --activate --allow-root

    # # Ensure permission
    # sudo chown -R "$FTP_USERNAME:$FTP_USERNAME" "/var/www/html"
    # sudo find /var/www/html -type d -exec chmod 777 {} ;
    # sudo find /var/www/html -type f -exec chmod 777 {} ;
    # sudo chmod -R 777 /var/www/html/wp-content

    # wp.phar redis enable --allow-root

    # cd /
fi

# addgroup -g "$FTP_USER_UID" -S "$FTP_USERNAME"
# adduser -u "$FTP_USER_UID" -D -S -G "$FTP_USERNAME" "$FTP_USERNAME"
# echo "$FTP_USERNAME:$FTP_PASSWORD" | chpasswd

# sed -i "s/FTP_USERNAME/$FTP_USERNAME/g" "/etc/php82/php-fpm.d/www.conf"

php-fpm82 -F