// Martinš
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename = "chat.txt";
    string message;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error opening " << filename << endl;
        return 1;
    }

    while (getline(infile, message)) {
        cout << "Sending message to prog4: " << message << endl;
    }

    infile.close();

    return 0;
}
