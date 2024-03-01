// Ija
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "chat.txt";
    std::string line;

    std::cout << "Chat History:\n";

    // Read and display the contents of the chat.txt file
    std::ifstream infile(filename);

    if (infile.is_open()) {
        while (std::getline(infile, line)) {
            std::cout << line << "\n";
        }
        infile.close();
    } else {
        std::cerr << "Error opening " << filename << std::endl;
        return 1;
    }

    return 0;
}