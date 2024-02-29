// Alan
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream chat("chat.txt");
    string lines;
    string message;
    int flag = 1;

    if (!chat.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }
    cout << endl << "-----Instructions-----" << endl;
    cout << "Enter address and lines format - @[name] [message]" << endl;
    cout << "Example: @Mark You are so smart!" << endl;
    cout << "Names: Alan, Mark, Ilja, Martins" << endl;
    cout << "----------------------" << endl << endl;
    do {
        cout << "==========Chat==========" << endl;
        while (getline(chat, lines)) {
            cout << lines << endl;
        }
        cout << "========================" << endl << endl;

        cout << "0 - Don't write" << endl;
        cout << "1 - Programm end" << endl;
        cout << "Enter the new message: ";
        getline(cin, message);

        if (message != "0" && message != "1" && message != "2") {
            ofstream outfile("chat.txt", ios::app);
            if (outfile.is_open()) {
                outfile << "Alan: " << message << endl;
                outfile.close();
            } else {
                cout << "Unable to open file for writing." << endl;
            }
        }

        if (message == "1") {
            cout << "Programm end..." << endl;
            flag = 0;
        }
        chat.close();
        chat.open("chat.txt");
    } while (flag != 0);

    return 0;
}
