// Martinš
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename;
    string message;

    cout << "Choose a chat file to write to (chat.txt or chat2.txt): ";
    cin >> filename;

    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cerr << "Error opening " << filename << " for writing" << endl;
        return 1;
    }

    cout << "Enter message to write to " << filename << " (type 'exit' to quit):" << endl;
    while (true) {
        getline(cin, message);
        if (message == "exit")
            break;
        outfile << message << endl;
    }

    outfile.close();

    return 0;
}

/*
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename = "chat2.txt";
    string message;

    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cerr << "Error opening " << filename << " for writing" << endl;
        return 1;
    }

    cout << "Enter message to write to chat.txt (type 'exit' to quit):" << endl;
    while (true) {
        getline(cin, message);
        if (message == "exit")
            break;
        outfile << message << endl;
    }

    outfile.close();

    return 0;
}*/