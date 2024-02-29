// Mark
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string chat_name = "chat.txt";
    fstream chat_file(chat_name);
    if(chat_file.is_open()) {
        string message;
        cout << "Enter your message: ";
        getline(cin, message);
        chat_file << message << endl;
        cout << "Message added to " << chat_name << ".\n" 
        << "Already recorded messages:" << endl;
        string line;
        while(getline(chat_file, line)) {
            cout << line << endl;
        }
        chat_file.close();
    } else {
        cerr << "Can't open " << chat_name << "." << endl;
        return 1;
    }
    return 0;
}