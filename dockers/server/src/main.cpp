#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    
    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error in socket creation" << std::endl;
        return -1;
    }

    // Prepare sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(666);

    // Bind
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error in binding" << std::endl;
        return -1;
    }

    // Listen
    listen(serverSocket, 3);

    while (true) {
        // Accept connection from an incoming client
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientSocket < 0) {
            std::cerr << "Error in accepting connection" << std::endl;
            return -1;
        }

        std::cout << "Connection accepted from " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port) << std::endl;

        // Create a new thread or process to handle the client connection
        // Example: You can create a new thread using std::thread
        // std::thread clientThread(clientHandler, clientSocket);

        // For simplicity, we will handle one client at a time in this example
        // clientThread.join();

        // For now, let's just close the client socket
        close(clientSocket);
    }
    
    close(serverSocket);

    return 0;
}
