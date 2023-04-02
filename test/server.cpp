#include "../server/server.h"

int main() {
    Server server(AF_INET, SOCK_STREAM, 0, AF_INET, 4761, "127.0.0.1");
    server.Bind(server.my_addr);
    server.ListenForConnection(5);
    server.AcceptConnection(server.con_addr);
    server.RecvMessage();
    server.Free();
    return 0;
}