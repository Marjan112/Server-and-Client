#include "client.h"

Client::Client(int domain, int type, int protocol, unsigned short family, unsigned short port, std::string ip) {
    sockfd = socket(domain, type, protocol);
    if(sockfd < 0) {
        perror("socket");
        quick_exit(-1);
    }
    dest_addr.sin_family = family;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    dest_addr.sin_zero[8] = '\0';
}

void Client::Connect(struct sockaddr_in dest_addr) {
    if(connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(struct sockaddr)) < 0) {
        perror("connect");
        quick_exit(-1);
    }
}

void Client::SendMessage(std::string msg) {
    if(write(sockfd, (void*)msg.c_str(), msg.size()) < 0) {
        perror("write");
        quick_exit(-1);
    }
}