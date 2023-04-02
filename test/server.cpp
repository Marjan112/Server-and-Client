#include "../server/server.h"

int main() {
    Server server(AF_INET, SOCK_STREAM, NULL, AF_INET, 4761, "127.0.0.1");
    server.Bind(server.addr1);
    server.ListenForConnection(5);
    server.AcceptConnection(server.addr2);
    server.RecvMessage();
    server.Free();
    return 0;
}