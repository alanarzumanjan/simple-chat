// Ilja
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename = "chat.txt";
    string message;

    cout << "Enter your message: ";
    getline(cin, message);

    ofstream outfile(filename, ios::app);

    if (outfile.is_open()) {
        outfile << message << endl;
        outfile.close();
        cout << "Message written to " << filename << endl;
    } else {
        cerr << "Error opening " << filename << endl;
        return 1;
    }

    return 0;
}