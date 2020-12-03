# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwki <junghwki@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 16:19:00 by junghwki          #+#    #+#              #
#    Updated: 2020/11/26 20:43:16 by junghwki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster

COPY	./srcs ./tmp

RUN		apt-get update && apt-get -y upgrade && apt-get install -y\
		nginx\
		mariadb-server\
		php-mysql\
		openssl\
		wget\
		php7.3-fpm

EXPOSE	80 443

CMD		bash tmp/run.sh
