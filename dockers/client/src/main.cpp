#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <cstdlib>

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    const char* serverIP = getenv("SERVER_IP");

    if (serverIP == nullptr) {
        std::cerr << "Environment variable SERVER_IP not set" << std::endl;
        return -1;
    }

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Error in socket creation" << std::endl;
        return -1;
    }

    // Prepare sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(666);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, serverIP, &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    // Connect to server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        
        while(1){
            auto now = std::chrono::system_clock::now();
    
            // Sleep until 1 second from now
            auto wakeup_time = now + std::chrono::seconds(10);
            std::this_thread::sleep_until(wakeup_time);
        }
    }

    std::cerr << "Connected to server on port 666" << std::endl;

    // Do something with the server connection

    // Close socket
    close(clientSocket);

    return 0;
}
