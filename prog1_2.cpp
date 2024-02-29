// Alan
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void global_chat_message();

int main(){
    ifstream chat("chat.txt");
    string lines;
    string message;
    int flag = 1;

    if (!chat.is_open()) {
        cout << "Unable to open file." << endl;
        return 1;
    }
    
    do{
        cout << endl;
        cout << "==========Menu==========" << endl;
        cout << "1 - Global chat message" << endl;
        cout << "2 - Private message" << endl;
        cout << "3 - Show my messages" << endl;
        switch(choice){
            case 1:
                global_chat_message();
            case 2:

            case 3:

            default:
                cout << "Uncorrect answer, repeat please" << endl;
        }
    }while(flag != 0);

    return 0;
}

void global_chat_message(){
    
}