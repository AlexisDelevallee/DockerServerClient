# Use an appropriate base image
FROM ubuntu:latest

# Update package lists and install GCC
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    g++ \
    && rm -rf /var/lib/apt/lists/*
    
# Copy the source code into the container
COPY ./src /app/src

# Set the working directory
WORKDIR /app
RUN g++ -o server -static ./src/main.cpp

# Any additional configuration or setup specific to machine2
CMD /app/server