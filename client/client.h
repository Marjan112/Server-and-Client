#ifndef CLIENT_H
#define CLIENT_H

#ifdef __linux__
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#elif defined WIN32
#include <Windows.h>
#endif
#include <iostream>

class Client {
private:
    int sockfd;
public:
    struct sockaddr_in dest_addr;
    Client(int domain, int type, int protocol, unsigned short family, unsigned short port, std::string ip);
    void Connect(struct sockaddr_in dest_addr);
    void SendMessage(std::string msg);
    void Free();
};

#endif /* CLIENT_H */