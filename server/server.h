#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

class Server {
private:
    int sockfd;
    unsigned int struct_size;
    int clientfd;
    int bytes_read;
    char msg[128];
public:
    struct sockaddr_in addr1;
    struct sockaddr_in addr2;
    Server(int domain, int type, int protocol, unsigned short family, unsigned short port, std::string ip);
    void Bind(struct sockaddr_in addr);
    void ListenForConnection(int n);
    void AcceptConnection(struct sockaddr_in addr);
    void RecvMessage();
    void Free();
};

#endif