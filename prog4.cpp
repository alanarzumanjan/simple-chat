// Martinš
#include <iostream>
#include <fstream>

using namespace std;

void writeMessage(const string& filename, const string& sender) {
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cerr << "Error opening " << filename << " for writing" << endl;
        return;
    }

    string message;
    cout << "Enter message to write to the chat (type 'exit' to quit):" << endl;
    while (true) {
        getline(cin, message);
        if (message == "exit")
            break;
        outfile << "[" << sender << "]: " << message << endl;
    }

    outfile.close();
}

int main() {
    string filename = "chat.txt";
    string sender;

    cout << "Enter your name: ";
    getline(cin, sender);

    cout << "Choose an option:\n1. Write to chat\n2. Read chat\n";
    int option;
    cin >> option;
    cin.ignore(); // Consume newline character

    if (option == 1) {
        writeMessage(filename, sender);
    } else if (option == 2) {
        ifstream infile(filename);
        if (!infile.is_open()) {
            cerr << "Error opening " << filename << " for reading" << endl;
            return 1;
        }

        string line;
        cout << "Chat Messages:" << endl;
        while (getline(infile, line)) {
            cout << line << endl;
        }

        infile.close();
    } else {
        cout << "Invalid option." << endl;
    }

    return 0;
}
