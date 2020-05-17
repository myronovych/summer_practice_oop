#include <QCoreApplication>
#include <iostream>
#include <QDataStream>
#include "contact.h"
#include "phonebook.h"
#include "unistd.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    Phonebook book;
    int choice = 0;
    while(choice != 7){
        cout << "What do you want to do? " << endl;
        cout << "1. Show contacts \n2. Add contact. \n3. Remove contact. \n4. Find contact by name. \n7.Quit\n";
        while(choice < 1 || choice > 7){
            cin >> choice;
        }
        if(choice == 1) {
            cout << book << endl;
        } else if(choice == 2){
            string name;
            string number;
            cout << "Enter name: " << endl;
            cin.ignore();
            getline (cin, name);
            cout << "Enter number: " << endl;
            cin.ignore();
            getline (cin, number);
            book.addContact(name,number);
         }else if(choice == 3){
            cout << book;
            cout << "Enter number of contact: ";
            int position;
            cin >> position;
            book.removeContact(position);
        }else if(choice == 4){
            cout << "Enter name of contact: ";
            string name;
            cin >> name;
            vector<int> expected= book.findContactByName(name);
            for(int i = 0; i < (int) expected.size();i++){
                cout << i << ") " << book.getContacts().at(expected.at(i));
            }

            int position;
            int action;

            cout << "Choose number of person" << endl;
            cin >> position;
            cout << "1. Add number \n2. Remove number \n3. Back" << endl;
            cout << "Choose number of action" << endl;
            cin >> action;

            if(action == 1){
                string num;
                cout << "Enter number: " << endl;
                cin.ignore();
                getline (cin, num);
                book.getContacts().at(expected.at(position)).addNum(num);
            } else if(action == 2){
                cout << book.getContacts().at(expected.at(position)) << endl;
                cout << "Which number to remove?" << endl;
                int pos;
                cin >> pos;
                book.getContacts().at(expected.at(position)).deleteNum(pos);
            }
        }
        choice = 0;
    }
    return a.exec();
}
