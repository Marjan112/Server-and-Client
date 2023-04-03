#include "../client/client.h"

std::string TOLOWER(std::string str) {
    for(int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main() {
    std::cout << "Do you want to connect to the server: ";
    std::string str;
    std::cin >> str;
    char msg[128];
    if(str == TOLOWER("Y")) {
        Client client(AF_INET, SOCK_STREAM, NULL, AF_INET, 4761, "127.0.0.1");
        client.Connect(client.dest_addr);
        std::cout << "Send message: ";
        std::cin.getline(msg, sizeof(msg));
        client.SendMessage(msg);
        client.Free();
    } else if(str == TOLOWER("YES")) {
        Client client(AF_INET, SOCK_STREAM, NULL, AF_INET, 4761, "127.0.0.1");
        client.Connect(client.dest_addr);
        std::cout << "Send message: ";
        std::cin.getline(msg, sizeof(msg));
        client.SendMessage(msg);
        client.Free();
    } else if(str == TOLOWER("n")) {
        std::cout << "Okay, then";
        sleep(3);
        std::cout << "\nBye!";
    } else if(str == TOLOWER("no")) {
        std::cout << "Okay, then";
        sleep(3);
        std::cout << "\nBye!";
    }
    return 0;
}