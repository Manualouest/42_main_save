all:
	docker compose -f ./srcs/docker-compose.yml up --build

stop:
	@if docker ps -a | grep "nginx" | grep -v -q "Exited" ; then \
		echo -n "Stopping " $$(docker ps -a | grep "nginx" | awk '{print $$2}') " with id "; \
		docker stop $$(docker ps -a | grep "nginx" | awk '{print $$1}'); \
	fi
	@if docker ps -a | grep "mariadb" | grep -v -q "Exited" ; then \
		echo -n "Stopping " $$(docker ps -a | grep "mariadb" | awk '{print $$2}') " with id "; \
		docker stop $$(docker ps -a | grep "mariadb" | awk '{print $$1}'); \
	fi
	@if docker ps -a | grep "wordpress" | grep -v -q "Exited" ; then \
		echo -n "Stopping " $$(docker ps -a | grep "wordpress" | awk '{print $$2}') " with id "; \
		docker stop $$(docker ps -a | grep "wordpress" | awk '{print $$1}'); \
	fi

clean: stop
	@if docker ps -a | grep -q "nginx"; then \
		echo -n "Removing " $$(docker ps -a | grep "nginx" | awk '{print $$2}') " with id "; \
		docker rm $$(docker ps -a | grep "nginx" | awk '{print $$1}'); \
	fi
	@if docker ps -a | grep -q "mariadb"; then \
		echo -n "Removing " $$(docker ps -a | grep "mariadb" | awk '{print $$2}') " with id "; \
		docker rm $$(docker ps -a | grep "mariadb" | awk '{print $$1}'); \
	fi
	@if docker ps -a | grep -q "wordpress"; then \
		echo -n "Removing " $$(docker ps -a | grep "wordpress" | awk '{print $$2}') " with id "; \
		docker rm $$(docker ps -a | grep "wordpress" | awk '{print $$1}'); \
	fi

status:
	@if docker ps -a | grep -q "nginx"; then \
		echo $$(docker ps -a | grep "nginx"); \
	fi
	@if docker ps -a | grep -q "mariadb"; then \
		echo $$(docker ps -a | grep "mariadb"); \
	fi
	@if docker ps -a | grep -q "wordpress"; then \
		echo $$(docker ps -a | grep "wordpress"); \
	fi

re: stop clean all