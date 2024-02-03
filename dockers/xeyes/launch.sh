#!/bin/bash

IP=$(/usr/sbin/ipconfig getifaddr en0)

xhost + "$IP"

docker run -it -e DISPLAY="${IP}:0" xeyes
