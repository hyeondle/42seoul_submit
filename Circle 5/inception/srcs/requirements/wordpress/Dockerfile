FROM debian:bullseye
RUN apt-get update && apt-get install -y php-fpm php-mysql wget mariadb-client
COPY conf/php-fpm.conf /etc/php/7.4/fpm/pool.d/www.conf
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -O /usr/local/bin/wp && \
    chmod +x /usr/local/bin/wp
EXPOSE 9000
COPY tools/wordpress-setup.sh /tmp/
WORKDIR /var/www/html
CMD ["bash", "/tmp/wordpress-setup.sh"]
