#!/bin/bash

function startServer(){
    docker-compose up --build -d doser
}

function startClient(){
    docker-compose up --build -d docli
}

startServer
startClient