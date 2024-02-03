#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a main window
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Client GUI");

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
    }

    std::cerr << "Connected to server on port 666" << std::endl;

    // Create a label widget
    QLabel *label = new QLabel("Connected");
    mainWindow.setCentralWidget(label);

    // Close socket
    close(clientSocket);

    // Display the main window
    mainWindow.show();

    // Run the application event loop
    return app.exec();
}
