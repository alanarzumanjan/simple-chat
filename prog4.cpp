//Mārtiņš
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
    cout << "Enter message to write to the chat (type 'q' to quit):" << endl;
    while (true) {
        getline(cin, message);
        if (message == "q")
            break;

        if (isPrivate) {
            outfile << sender << "(P) sent " << receiver << " - " << message << endl;
        } else {
            outfile << sender << "(G) - " << message << endl;
        }
    }

    outfile.close();
}

void displayMessages(const string& filename, const string& username, bool showGlobal) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error opening " << filename << " for reading" << endl;
        return;
    }

    string line;
    cout << (showGlobal ? "Global Chat Messages:" : "Private Messages:") << endl;
    while (getline(infile, line)) {
        if (showGlobal && line.find("(G) - ") != string::npos) {
            cout << line << endl;
        } else if (!showGlobal && line.find("(P) sent " + username) != string::npos) {
            cout << line << endl;
        }
    }

    infile.close();
}

int main() {
    string filename = "chat.txt";
    string sender;
    int option;

    cout << "Enter your name: ";
    getline(cin, sender);

    cout << "Choose an option:\n1. Write to global chat\n2. Send a private message\n3. Check messages\n";
    cin >> option;
    cin.ignore();

    switch(option) {
        case 1:
            writeMessage(filename, sender, "", false);
            break;
        case 2: {
            string receiver;
            cout << "Enter recipient's name: ";
            getline(cin, receiver);
            writeMessage(filename, sender, receiver, true);
            break;
        }
        case 3:
            displayMessages(filename, sender, true);
            displayMessages(filename, sender, false);
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }

    return 0;
}
