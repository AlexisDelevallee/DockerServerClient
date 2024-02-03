#!/bin/bash

doser_addr=$(nslookup doser | grep 'Address:' | awk '{ print $2 }' | sed -n '2p')

echo "DOSER_ADDR is $doser_addr"

export SERVER_IP=$doser_addr

#sleep 360