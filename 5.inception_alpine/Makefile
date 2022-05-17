NAME = inception

all: prune reload

setup:
	@ sudo sh ./srcs/requirements/tools/set_for_docker.sh

linux:
	@ echo "127.0.0.1 seonhjeo.42.fr" >> /etc/hosts

stop:
	@ docker-compose -f srcs/docker-compose.yml down

clean: stop
	@ rm -rf ~/Desktop/inception

prune: clean
	@ docker system prune -f

reload:
	@ docker-compose -f srcs/docker-compose.yml up --build

.PHONY: linux stop clean prune reload all
