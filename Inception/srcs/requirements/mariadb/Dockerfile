FROM alpine:3.20

# update alpine
RUN ["apk", "update"]
RUN ["apk", "upgrade"]

# get mariadb
RUN ["apk", "add", "mariadb", "mariadb-client", "mariadb-server-utils"]
RUN ["apk", "add", "openrc"]

# setup mariadb
COPY ["/requirements/mariadb/conf/default.conf", "/etc/mysql/mariadb.conf.d/default.conf"]

RUN ["mkdir", "-p", "/run/mysql"]
RUN ["mkdir", "-p", "/usr/local/mysql"]

RUN ["chown", "-R", "mysql:mysql", "/run/mysql"]
RUN ["chown", "-R", "mysql:mysql", "/usr/local/mysql"]

RUN ["openrc"]
RUN ["touch", "/run/openrc/softlevel"]

ADD ["/requirements/mariadb/tools/setupDB.sh", "."]
RUN ["chmod", "+x", "setupDB.sh"]
CMD ["./setupDB.sh"]
