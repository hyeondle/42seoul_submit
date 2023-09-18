DC=docker compose -f ./srcs/docker-compose.yml
DOCKER=docker

all: build up

build:
	$(DC) build

up:
	$(DC) up -d

down:
	$(DC) down

logs:
	$(DC) logs

clean: down
	$(DOCKER) volume prune -f
	$(DOCKER) system prune -f

restart: down up

rm: down
	$(DOCKER) volume rm $$(docker volume ls -q)
	$(DOCKER) rmi $$(docker images -q)

.PHONY: all build up down logs clean restart rm
