# Base Image
FROM alpine:latest

RUN apk update && \
    apk add --no-cache xeyes

# Set a working directory
WORKDIR /work

# Start a shell by default
CMD ["ash"]