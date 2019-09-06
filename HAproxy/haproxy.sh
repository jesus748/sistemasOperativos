#!/usr/bin/env bash
apt-get update
apt-get install -y haproxy
echo -e "ENABLED=1" >> /etc/default/haproxy
sudo mv /etc/haproxy/haproxy.cfg{,.original}

# configuració HAproxy

echo -e "global" >> /etc/haproxy/haproxy.cfg
echo -e "\tlog /dev/log local0" >> /etc/haproxy/haproxy.cfg
echo -e "\tlog 127.0.0.1 local1 notice" >> /etc/haproxy/haproxy.cfg
echo -e "\tmaxconn 4096" >> /etc/haproxy/haproxy.cfg
echo -e "\tuser haproxy" >> /etc/haproxy/haproxy.cfg
echo -e "\tgroup haproxy" >> /etc/haproxy/haproxy.cfg
echo -e "\tdaemon" >> /etc/haproxy/haproxy.cfg
echo -e "defaults" >> /etc/haproxy/haproxy.cfg
echo -e "\tlog global" >> /etc/haproxy/haproxy.cfg
echo -e "\tmode http" >> /etc/haproxy/haproxy.cfg
echo -e "\toption httplog" >> /etc/haproxy/haproxy.cfg
echo -e "\toption dontlognull" >> /etc/haproxy/haproxy.cfg
echo -e "\tretries 3" >> /etc/haproxy/haproxy.cfg
echo -e "\toption redispatch" >> /etc/haproxy/haproxy.cfg
echo -e "\tmaxconn 2000" >> /etc/haproxy/haproxy.cfg
echo -e "\tcontimeout 5000" >> /etc/haproxy/haproxy.cfg
echo -e "\tclitimeout 50000" >> /etc/haproxy/haproxy.cfg
echo -e "\tsrvtimeout 50000" >> /etc/haproxy/haproxy.cfg
echo -e "listen webfarm" >> /etc/haproxy/haproxy.cfg
echo -e "bind 0.0.0.0:80" >> /etc/haproxy/haproxy.cfg
echo -e "\tmode http" >> /etc/haproxy/haproxy.cfg
echo -e "\tstats enable" >> /etc/haproxy/haproxy.cfg
echo -e "\tstats uri /haproxy?stats" >> /etc/haproxy/haproxy.cfg
echo -e "\tbalance roundrobin" >> /etc/haproxy/haproxy.cfg
echo -e "\toption httpclose" >> /etc/haproxy/haproxy.cfg
echo -e "\toption forwardfor" >> /etc/haproxy/haproxy.cfg
echo -e "\tserver web01 172.19.0.3:80 check" >> /etc/haproxy/haproxy.cfg
echo -e "\tserver web02 172.19.0.4:80 check" >> /etc/haproxy/haproxy.cfg

sudo service haproxy start
sudo service haproxy restart
