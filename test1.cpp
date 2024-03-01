#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Message {
public:
    std::string sender;
    std::string recipient;
    std::string content;
    bool isGlobal;

    Message(std::string sender, std::string content, bool isGlobal = true)
        : sender(sender), content(content), isGlobal(isGlobal) {}

    Message(std::string sender, std::string recipient, std::string content)
        : sender(sender), recipient(recipient), content(content), isGlobal(false) {}

    std::string toString() const {
        if (isGlobal) {
            return sender + " talk(G) - " + content;
        } else {
            return sender + "(P) sent " + recipient + " - " + content;
        }
    }
};

class ChatSystem {
private:
    std::vector<Message> messages;
    std::string currentUser;

public:
    void setCurrentUser(const std::string& user) {
        currentUser = user;
    }

    std::string getCurrentUsername() const {
        return currentUser;
    }

    void writeMessage(const Message& message) {
        messages.push_back(message);

        std::ofstream file("chat.txt", std::ios::app);
        if (file.is_open()) {
            file << message.toString() << "\n";
            file.close();
        }
    }

    std::vector<Message> searchGlobalMessages() const {
        std::vector<Message> result;
        for (const auto& message : messages) {
            if (message.isGlobal) {
                result.push_back(message);
            }
        }
        return result;
    }

    std::vector<Message> searchPrivateMessages(const std::string& recipient) const {
        std::vector<Message> result;
        for (const auto& message : messages) {
            if (!message.isGlobal && message.recipient == recipient) {
                result.push_back(message);
            }
        }
        return result;
    }

    void displayUserMessages(const std::string& username) const {
        std::cout << "Messages for " << username << ":\n";
        for (const auto& message : messages) {
            if (message.sender == username || (!message.isGlobal && message.recipient == username)) {
                std::cout << message.toString() << "\n";
            }
        }
    }

    void loadMessagesFromFile() {
        std::ifstream file("chat.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string sender, type;
                iss >> sender >> type;

                if (type == "talk(G)") {
                    std::getline(iss, line);
                    messages.emplace_back(sender, line);
                } else if (type == "(P) sent") {
                    std::string recipient;
                    iss >> recipient;
                    std::getline(iss, line);
                    messages.emplace_back(sender, recipient, line);
                }
            }
            file.close();
        }
    }
};

int main() {
    ChatSystem chatSystem;
    chatSystem.setCurrentUser("Ilja");

    // Load and display messages from the file
    chatSystem.loadMessagesFromFile();
    chatSystem.displayUserMessages(chatSystem.getCurrentUsername());

    while (true) {
        std::cout << "Choose message type (1: Global, 2: Private, 0: Exit): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        std::string sender, recipient, content;

        sender = chatSystem.getCurrentUsername();

        if (choice == 1) {
            // Global message
            std::cout << "Enter message content: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, content);

            Message globalMessage(sender, content);
            chatSystem.writeMessage(globalMessage);
        } else if (choice == 2) {
            // Private message
            std::cout << "Enter recipient's name (@Mark, @Alan, @Martin, @Ilja): ";
            std::cin >> recipient;

            std::cout << "Enter private message content: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, content);

            Message privateMessage(sender, recipient, content);
            chatSystem.writeMessage(privateMessage);
        }

        chatSystem.displayUserMessages(chatSystem.getCurrentUsername());
    }

    return 0;
}