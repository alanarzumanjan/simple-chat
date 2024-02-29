// Alan
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write_global_chat();
void write_private_message();
void check_global_chat();

int main(){
    bool flag = true;
    short choice;
    
    do{
        cout << endl;
        cout << "==========Menu==========" << endl;
        cout << "1 - Write Global chat" << endl;
        cout << "2 - Write Private message" << endl;
        cout << "3 - Check Global chat" << endl;
        cout << "4 - Check private chats" << endl;
        cout << "5 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                write_global_chat();
                break;
            case 2:
                write_private_message();
                break;
            case 3:
                check_global_chat();
                break;
            case 4:

                break;
            case 5:
                cout << "Exit... :)" << endl;
                flag = false;
                break;
            default:
                cout << "Uncorrect answer, repeat please" << endl;
                break;
        }
    }while(flag);

    return 0;
}

void write_global_chat(){
    ofstream chat("chat.txt", ios::app);
    string message;
    cin.ignore();
    cout << "Enter your message: ";
    getline(cin, message);
    if(chat.is_open()){
        chat << "Alan(G): " << message << endl;
    }
    chat.close();
}

void write_private_message(){
    ofstream chat("chat.txt", ios::app);
    string message;
    string person;
    bool flag = true;
    do{
        cout << "Users: ";
        cout << "Alan, Mark, Ilja, Martins" << endl;
        cout << "Enter person name witch you want sent message: ";
        cin >> person;
        if(person != "Alan" && person != "Mark" && person != "Ilja" && person != "Martins"){
            cout << "Invalid choice, please try again" << endl;
        } else{
            flag = false;
            }
    }while(flag);
    
    cout << "Enter your messsage: ";
    cin.ignore();
    getline(cin, message);
    if(chat.is_open()){
        chat << "Alan(P) sent " << person << ": " << message << endl;
    }
    chat.close();
}

void check_global_chat(){
    ifstream chat("chat.txt");
    for(short i=0; i < ; i++){

    }
}