#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

using namespace std;

void* serverFunction(void* arg) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        cout << "Socket creation failed" << endl;
        return NULL;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        cout << "Bind failed" << endl;
        close(server_fd);
        return NULL;
    }

    if (listen(server_fd, 3) < 0) {
        cout << "Listen failed" << endl;
        close(server_fd);
        return NULL;
    }

    cout << "Server: Waiting for connections..." << endl;
    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        cout << "Accept failed" << endl;
        close(server_fd);
        return NULL;
    }

    read(new_socket, buffer, BUFFER_SIZE);
    cout << "Server received: " << buffer << endl;
    send(new_socket, "Hello from Server", strlen("Hello from Server"), 0);
    close(new_socket);
    close(server_fd);
    return NULL;
}

void clientFunction() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        cout << "Socket creation failed" << endl;
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sleep(1); // Ensure the server starts first
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        cout << "Connection failed" << endl;
        close(sock);
        return;
    }

    send(sock, "Hello from Client", strlen("Hello from Client"), 0);
    read(sock, buffer, BUFFER_SIZE);
    cout << "Client received: " << buffer << endl;
    close(sock);
}

int main() {
    pthread_t serverThread;
    pthread_create(&serverThread, NULL, serverFunction, NULL);
    clientFunction();
    pthread_join(serverThread, NULL);
    return 0;
}