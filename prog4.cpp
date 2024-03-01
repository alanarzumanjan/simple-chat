// Martinš
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


void writeMessage(const string& filename, const string& sender, const string& receiver, bool isPrivate) {
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
        
        
        if (isPrivate) {
            outfile << sender << "(P) " << receiver << "" << message << endl;
        } else {
            outfile << sender << "(G) " << message << endl;
        }
    }

    outfile.close();
}

int main() {
    string filename = "chat.txt";
    string sender;
    int option;

    cout << "Enter your name: ";
    getline(cin, sender);

    cout << "Choose an option:\n1. Write to global chat\n2. Send a private message\n";
    cin >> option;
    cin.ignore();

    switch(option) {
        case 1:
            writeMessage(filename, sender, "", false);
            break;
        case 2: {
            string receiver;
            cout << "Enter receiver's name: ";
            getline(cin, receiver);
            writeMessage(filename, sender, receiver, true);
            break;
        }
        default:
            cout << "Error." << endl;
            break;
    }

    return 0;
}
