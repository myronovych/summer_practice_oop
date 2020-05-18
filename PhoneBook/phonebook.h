#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <contact.h>
using namespace std;

class Phonebook{
private:
    vector<Contact> _contacts;
public:
    Phonebook(){};

    const vector<Contact>& getContacts() const{
        return _contacts;
    }

    vector<Contact>& getContacts() {
        return _contacts;
    }


    void addContact(string name, string num){
        _contacts.push_back(Contact(name,num));
        sort(getContacts().begin(),getContacts().end(),[](const Contact & contact1, const Contact & contact2){
            return contact1.getName() < contact2.getName();
        });
    }

    void removeNumberForContact(Contact& contact, int at){
        if(at >= 1 && at <= (int) contact.getNums().size()){
            contact.deleteNum(at);
        } else {
            cout << "Wrong input" << endl;
        }
    }

    void removeContact(int at){
        if(at >= 1 && at <= (int) getContacts().size()){
            getContacts().erase(getContacts().begin() + at - 1);
        } else {
            cout << "Wrong input" << endl;
        }
    }

    vector<int> findContactByName(const string& name){
        vector<int> result; //position which match name
        for (size_t i = 0; i < getContacts().size(); ++i)
        {
            if(getContacts().at(i).getName().find(name) != string::npos){
                result.push_back(i);
            }
        }
        return result;
    }

    vector<int> findContactByNumber(const string& phoneNum) {
        vector<int> result; //position which match number
        for (size_t i = 0; i < getContacts().size(); ++i) {
            for(int j = 0; j < (int) getContacts().at(i).getNums().size(); j++){
                if(getContacts().at(i).getNums().at(j).find(phoneNum) != string::npos){
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }

};

ostream& operator<<( ostream& stream, const Phonebook& phonebook){
    cout << "Your contacts: " << endl;
   for (size_t i = 0; i < phonebook.getContacts().size(); ++i)
   {
       stream << i+1 << ") " << phonebook.getContacts().at(i).getName() << endl;

   }

   return stream;
}
#endif // PHONEBOOK_H
