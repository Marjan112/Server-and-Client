#include "server.h"

Server::Server(int domain, int type, int protocol, unsigned short family, unsigned short port, std::string ip) {
    if((sockfd = socket(domain, type, protocol)) < 0) {
        throw("socket");
    }
    addr1.sin_family = family;
    addr1.sin_port = htons(port);
    addr1.sin_addr.s_addr = inet_addr(ip.c_str());
    addr1.sin_zero[8] = '\0';
}

void Server::Bind(struct sockaddr_in addr) {
    if(bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr)) < 0) {
        throw("bind");
    }
}

void Server::ListenForConnection(int n) {
    if(listen(sockfd, n) < 0) {
        throw("listen");
    }
}

void Server::AcceptConnection(struct sockaddr_in addr) {
    struct_size = sizeof(addr);
    if((clientfd = accept(sockfd, (struct sockaddr*)&addr, &struct_size)) < 0) {
        throw("accept");
    }
}

void Server::RecvMessage() {
    if((bytes_read = read(clientfd, msg, sizeof(msg))) < 0) {
        throw("read");
    }
    msg[bytes_read] = '\0';
    std::cout << "Recieved message from client is " << "\"" << msg << "\"";
}

void Server::Free() {
    close(clientfd);
    close(sockfd);
}
