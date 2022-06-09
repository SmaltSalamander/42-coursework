# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 19:26:01 by sbienias          #+#    #+#              #
#    Updated: 2022/06/04 14:32:37 by sbienias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include srcs/.env
export $(shell sed 's/=.*//' srcs/.env)
SRCS = srcs/docker-compose.yml

prep: $(SRCS)
	# mkdir -p /Users/sbienias/data/db && mkdir /Users/sbienias/data/wordprs
	docker volume create --name=db --opt device=/Users/sbienias/data/db --opt type=none
	docker volume create --name=wordprs --opt device=/Users/sbienias/data/wordprs --opt type=none
up:
	cd srcs && docker-compose up --build -d --remove-orphans && cd ..

down:
	cd srcs && docker-compose down -t 2 && cd ..
	@rm -rf ~/data/mariadb

fdown:
	cd srcs && docker-compose down -t 2 -v && cd ..
	@rm -rf ~/data

clean:
	cd srcs && docker-compose down --rmi all

dockercleanup:
	docker rm -vf $(docker ps -aq)
	docker rmi -f $(docker images -aq)

.PHONY: up down fdown clean