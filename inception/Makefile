LOGIN	= mbirou

all: up

up: title
	@mkdir -p /home/$(LOGIN)
	@mkdir -p /home/$(LOGIN)/data
	@mkdir -p /home/$(LOGIN)/data/mariadb
	@mkdir -p /home/$(LOGIN)/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up -d

down:
	docker compose -f ./srcs/docker-compose.yml down

clean: down
	rm -rf /home/$(LOGIN)/data

fclean: clean
	docker system prune -af

re: fclean all