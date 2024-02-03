#!/bin/bash

function startServer(){
    docker-compose up --build -d doser
}

function startClient(){
    # Forward IP addr for X11.
    export IP=$(/usr/sbin/ipconfig getifaddr en0)
    xhost + "$IP"

    #export DOSER_IP=$(nslookup doser | grep 'Address:' | awk '{ print $2 }' | sed -n '2p')
    export DOSER_IP=$(docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' doser)
    echo DOSER_IP is $DOSER_IP
    docker-compose up --build -d docli 
}

docker-compose down

startServer
startClient