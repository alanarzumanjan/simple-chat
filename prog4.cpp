// Martinš
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename = "chat.txt";
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
}
