# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 19:26:01 by sbienias          #+#    #+#              #
#    Updated: 2022/12/03 16:04:54 by sbienias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cd srcs && docker-compose up --build -d --remove-orphans && cd ..

clean:
	cd srcs && docker-compose down --rmi all

fclean: clean dockercleanup

setup-domain:
	@sudo bash -c 'echo "127.0.0.1	sbienias.42.fr" >> /etc/hosts'

re:	clean all

dockercleanup:
	docker volume rm v-db v-wordprs
	sudo rm -rf /home/sbienias/data/

cleanmac:
	rm -rf /Users/sbienias/data/

.PHONY: all clean dockercleanup

# Enter a container for debugging
# docker exec -it Container_ID sh
