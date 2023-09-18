FROM debian:bullseye
RUN apt-get update && apt-get install -y mariadb-server
COPY conf/ /etc/mysql/mariadb.conf.d/
COPY tools/init-database.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init-database.sh
VOLUME ["/var/lib/mysql"]
EXPOSE 3306
CMD ["/usr/local/bin/init-database.sh"]
