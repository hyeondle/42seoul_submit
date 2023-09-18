#!/bin/bash
mkdir -p /etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/hyeondle.42.fr.key \
    -out /etc/nginx/ssl/hyeondle.42.fr.crt \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42Seoul/CN=hyeondle.42.fr"