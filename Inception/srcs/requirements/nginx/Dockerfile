FROM alpine:3.20

# update alpine
RUN ["apk", "update"]
RUN ["apk", "upgrade"]

# get nginx
RUN ["apk", "add", "nginx"]

# setup conf file
RUN ["rm", "-rf", "/etc/nginx/http.d/default.conf"]
COPY ["requirements/nginx/conf/default.conf", "/etc/nginx/http.d/default.conf"]

# setup ssl
RUN ["apk", "add", "openssl"]

RUN ["mkdir", "-p", "/etc/nginx/ssl"]
RUN ["openssl", "req", "-x509", "-nodes",\
		"-keyout", "/etc/nginx/ssl/inception.key",\
		"-out", "/etc/nginx/ssl/inception.crt",\
		"-subj", "/C=FR/ST=Charente/L=Angouleme/O=42/OU=42/CN=Inception/emailAddress=mbirou@student.42angouleme.fr"]


CMD ["nginx", "-g", "daemon off;"]