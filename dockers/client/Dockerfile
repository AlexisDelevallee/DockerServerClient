# to verify if the 666 port is exposed : 
#   docker-compose exec docli telnet doser 666

# Use an appropriate base image
FROM ubuntu:latest

# Update package lists and install GCC
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    g++ \
    telnet \
    dnsutils \
    build-essential \
    qtbase5-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy the source code into the container
COPY ./src /app/src
COPY ./wait.sh /app/wait.sh

# Set the working directory
WORKDIR /app

RUN chmod +x wait.sh

# Build your Qt project
RUN cd src && \
    qmake && \
    make

RUN mv src/src ./client

#RUN g++ -o client -static ./src/main.cpp
#RUN g++ -std=c++11 -o client ./src/main.cpp -lQt5Widgets

# Export the configuration
RUN echo $SERVER_IP

# Any additional configuration or setup specific to machine2
CMD /app/client
#CMD ./wait.sh