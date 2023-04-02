#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

class Client {
private:
    int sockfd;
public:
    struct sockaddr_in dest_addr;
    Client(int domain, int service, int protocol, unsigned short family, unsigned short port, std::string ip);
    void Connect(struct sockaddr_in dest_addr);
    void SendMessage(std::string msg);
};

#endif