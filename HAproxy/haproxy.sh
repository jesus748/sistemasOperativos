#!/usr/bin/env bash
apt-get update
apt-get install -y haproxy
echo -e "ENABLED=1" >> /etc/default/haproxy
mv /etc/haproxy/haproxy.cfg{,.original}

# configuració HAproxy

echo -e "global" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tlog /dev/log local0" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tlog 127.0.0.1 local1 notice" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tmaxconn 4096" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tuser haproxy" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tgroup haproxy" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tdaemon" >> /etc/default/haproxy/haproxy.cfg
echo -e "defaults" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tlog global" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tmode http" >> /etc/default/haproxy/haproxy.cfg
echo -e "\toption httplog" >> /etc/default/haproxy/haproxy.cfg
echo -e "\toption dontlognull" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tretries 3" >> /etc/default/haproxy/haproxy.cfg
echo -e "\toption redispatch" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tmaxconn 2000" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tcontimeout 5000" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tclitimeout 50000" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tsrvtimeout 50000" >> /etc/default/haproxy/haproxy.cfg
echo -e "listen webfarm" >> /etc/default/haproxy/haproxy.cfg
echo -e "blind 0.0.0.0:80" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tmode http" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tstats enable" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tstats uri /haproxy?stats" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tbalance roundrobin" >> /etc/default/haproxy/haproxy.cfg
echo -e "\toption httpclose" >> /etc/default/haproxy/haproxy.cfg
echo -e "\toption forwardfor" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tserver web01 192.168.200.3:80 check" >> /etc/default/haproxy/haproxy.cfg
echo -e "\tserver web02 192.168.200.4:80 check" >> /etc/default/haproxy/haproxy.cfg
service haproxy start
service haproxy restart
