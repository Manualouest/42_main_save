FROM alpine:3.20

# update alpine
RUN ["apk", "update"]
RUN ["apk", "upgrade"]

RUN ["apk", "add", "php"]
RUN ["apk", "add", "mariadb-client"]
RUN ["apk", "add", "wget", "tar", "sudo"]

# get wordpress
RUN	["wget", "https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar"]
RUN	["chmod", "+x", "wp-cli.phar"]
RUN	["mv", "wp-cli.phar", "/usr/local/bin/wp.phar"]
RUN	["mkdir", "-p", "/var/www"]
RUN	["mkdir", "-p", "/var/www/html"]

ADD ["/requirements/wordpress/tools/setupWP.sh", "."]
RUN ["chmod", "+x", "setupWP.sh"]
CMD ["./setupWP.sh"]



# RUN ["rm", "-rf", "/home/mbirou/data/html/", "wp-config-sample.php"]
# COPY ["requirements/wordpress/conf/default.conf", "/home/mbirou/data/html/default.conf"]

