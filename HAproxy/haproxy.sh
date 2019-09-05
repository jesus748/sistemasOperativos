#!/usr/bin/env bash
apt-get update
apt-get install -y haproxy
mv /etc/haproxy/haproxy.cfg{,.original}
echo "global \n\tlog /dev/log   local0 \n\tlog 127.0.0.1   local1 notice \n\tmaxconn 4096 \n\tuser haproxy \n\tgroup haproxy \n\tdaemon \ndefaults \n\tlog     global \n\tmode    http \n\toption  httplog \n\toption  dontlognull \n\tretries 3 \n\toption redispatch \n\tmaxconn 2000 \n\tcontimeout     5000 \n\tclitimeout     50000 \n\tsrvtimeout     50000 \nlisten webfarm \n\tbind 0.0.0.0:80 \n\tmode http \n\tstats enable \n\tstats uri /haproxy?stats \n\tbalance roundrobin \n\toption httpclose \n\toption forwardfor \n\tserver webserver01 192.168.205.16:80 check \n\tserver webserver02 192.168.205.17:80 check" >> /etc/haproxy/haproxy.cfg
sudo service haproxy start
