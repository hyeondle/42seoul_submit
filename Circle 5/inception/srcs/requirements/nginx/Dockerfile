FROM debian:bullseye
RUN apt-get update && apt-get install -y nginx openssl
COPY conf/ /etc/nginx/conf.d/
COPY tools/generate-ssl.sh /tmp/
RUN bash /tmp/generate-ssl.sh
EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]
