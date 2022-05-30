# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 19:26:01 by sbienias          #+#    #+#              #
#    Updated: 2022/05/26 19:26:19 by sbienias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include srcs/.env
export $(shell sed 's/=.*//' srcs/.env)

up:
	cd srcs && docker-compose up --build -d --remove-orphans && cd ..

down:
	cd srcs && docker-compose down -t 2 && cd ..
	@rm -rf ~/data/mariadb

fdown:
	cd srcs && docker-compose down -t 2 -v && cd ..
	@rm -rf ~/data

clean:
	docker-compose down --rmi all

.PHONY: up down fdown clean