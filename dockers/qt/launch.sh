#!/bin/bash

IP=$(/usr/sbin/ipconfig getifaddr en0)

xhost + "$IP"

docker build -t qt .
docker run -it -e DISPLAY="${IP}:0" qt