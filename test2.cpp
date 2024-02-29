#include <iostream>
#include <fstream>

void sendMessage(const std::string& sender, const std::string& message, const std::string& recipient) {
    std::ofstream chatFile("chat.txt", std::ios::app);
    chatFile << sender << " to " << recipient << ": " << message << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <recipient> <message>" << std::endl;
    } else {
        std::string recipient = argv[1];
        std::string message = argv[2];
        sendMessage("test1", message, recipient);
    }

    return 0;
}