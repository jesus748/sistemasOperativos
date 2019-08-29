#!/usr/bin/env bash
cp /var/www/html/index.html /home/vagrant

sudo apt-get update
sudo apt-get -y install apache2 --fix-missing

mv /home/vagrant/index.html /var/www/html/
