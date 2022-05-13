all:
	clean setup up
up:
	@docker-compose -f ./srcs/docker-compose.yml up

setup:
	sudo sh ./srcs/requirements/tools/set_for_docker.sh

down:
	@docker-compose -f ./srcs/docker-compose.yml down

re:
	@docker-compose -f srcs/docker-compose.yml up --build

clean:
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q);\
	docker system prune -a;

.PHONY: all re up setup down clean
