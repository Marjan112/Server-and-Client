#include "server.h"

Server::Server(int domain, int service, int protocol, unsigned short family, unsigned short port, std::string ip) {
    sockfd = socket(domain, service, protocol);
    if(sockfd < 0) {
        perror("socket");
        quick_exit(-1);
    }
    my_addr.sin_family = family;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    my_addr.sin_zero[8] = '\0';
}

void Server::Bind(struct sockaddr_in my_addr) {
    if(bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) < 0) {
        perror("bind");
        quick_exit(-1);
    }
}

void Server::ListenForConnection(int clients) {
    if(listen(sockfd, clients) < 0) {
        perror("listen");
        quick_exit(-1);
    }
}

void Server::AcceptConnection(struct sockaddr_in con_addr) {
    struct_size = sizeof(con_addr);
    clientfd = accept(sockfd, (struct sockaddr*)&con_addr, &struct_size);
    if(clientfd < 0) {
        perror("accept");
        quick_exit(-1);
    }
}

void Server::RecvMessage() {
    bytes_read = read(clientfd, msg, sizeof(msg));
    if(bytes_read < 0) {
        perror("read");
        quick_exit(-1);
    }
    msg[bytes_read] = '\0';
    std::cout << "Recieved message from client is " << "\"" << msg << "\"";
}

void Server::Free() {
    close(clientfd);
    close(sockfd);
}
