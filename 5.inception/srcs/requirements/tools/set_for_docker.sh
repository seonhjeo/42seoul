#!/bin/bash

echo "\033[47;35m--Setting for docker--\033[0m\n"

sudo mkdir ~/data
sudo mkdir ~/data/wordpress
sudo mkdir ~/data/mariadb
sudo chmod -R 777 ~/data/

sudo apt-get remove docker docker-engine docker.io containerd runc

sudo apt-get update
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common

sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo apt-key fingerprint 0EBFCD88

sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

sudo apt-get update
sudo apt-get install vim make
sudo apt-get install docker-ce docker-ce-cli containerd.io
docker run hello-world

sudo apt install jq
VERSION=$(curl --silent https://api.github.com/repos/docker/compose/releases/latest | jq .name -r)
DESTINATION=/usr/bin/docker-compose
sudo curl -L https://github.com/docker/compose/releases/download/${VERSION}/docker-compose-$(uname -s)-$(uname -m) -o $DESTINATION
sudo chmod 755 $DESTINATION

usermod -aG docker ${USER}

sudo gpasswd -a $USER docker
newgrp docker

echo  "\033[44;33m@@@It's set up for docker@@@\033[0m\n\n"
