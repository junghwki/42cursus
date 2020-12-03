# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwki <junghwki@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 16:46:10 by junghwki          #+#    #+#              #
#    Updated: 2020/11/26 22:02:41 by junghwki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/bash

mv ./tmp/default ./etc/nginx/sites-available/default
openssl req -newkey rsa:2048 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=42Seoul/CN=kjh" -keyout localhost.dev.key -out localhost.dev.crt;
mv localhost.dev.crt ./etc/ssl/certs/
mv localhost.dev.key ./etc/ssl/private/
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xf phpMyAdmin-5.0.2-all-languages.tar.gz;
mv phpMyAdmin-5.0.2-all-languages ./phpmyadmin
mv phpmyadmin/ ./var/www/html/
mv ./tmp/config.inc.php ./var/www/html/phpmyadmin/
wget https://wordpress.org/latest.tar.gz
tar -xf latest.tar.gz;
mv wordpress ./var/www/html/
mv ./tmp/wp-config.php ./var/www/html/wordpress/wp-config.php
rm -rf latest.tar.gz phpMyAdmin-5.0.2-all-languages.tar.gz
chown -R www-data:www-data ./var/www/html/wordpress
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER 'junghwki'@'%' identified by '';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'junghwki'@'%' IDENTIFIED BY '' WITH GRANT OPTION;" | mysql -u root --skip-password
service nginx start
service php7.3-fpm start
service mysql reload
bash
