#include "../client/client.h"

int main() {
    Client client(AF_INET, SOCK_STREAM, 0, AF_INET, 4761, "127.0.0.1");
    client.Connect(client.dest_addr);
    char msg[128];
    std::cout << "Send message: ";
    std::cin.getline(msg, sizeof(msg));
    client.SendMessage(msg);
    client.Free();
    return 0;
}