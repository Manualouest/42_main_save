all:
	docker compose -f ./srcs/docker-compose.yml up

stop:
	@if docker ps -a | grep "nginx" | grep -v -q "Exited"; then \
		docker stop $$(docker ps -a -q); \
	fi
	@if docker ps -a | grep "mariadb" | grep -v -q "Exited"; then \
		docker stop $$(docker ps -a -q); \
	fi
	@if docker ps -a | grep "wordpress" | grep -v -q "Exited"; then \
		docker stop $$(docker ps -a -q); \
	fi

clean:
	@if docker ps -a | grep -q "nginx"; then \
		docker rm $$(docker ps -a -q); \
	fi
	@if docker ps -a | grep -q "mariadb"; then \
		docker rm $$(docker ps -a -q); \
	fi
	@if docker ps -a | grep -q "wordpress"; then \
		docker rm $$(docker ps -a -q); \
	fi

status:
	docker ps -a -q