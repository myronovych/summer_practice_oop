#ifndef CONTACT_H
#define CONTACT_H
#include <QString>
#include <QVector>
#include <iostream>

using namespace std;
class Contact{
private:
    string _name;
    vector<string> _numbers;
public:

    Contact(const string& name, const string& num): _name(name){
        _numbers.push_back(num);
    };

    bool operator ()(const Contact & contact1, const Contact & contact2)
        {
            return contact1.getName() < contact2.getName();

        }

    const string getName() const {
        return _name;
    }

    const vector<string>& getNums() const{
        return _numbers;
    }

    vector<string>& getNums() {
        return _numbers;
    }

    void addNum(const string& num){
        _numbers.push_back(num);
    }

    void deleteNum(const int& at){
        _numbers.erase(_numbers.begin() + at - 1);
    }

};

 ostream& operator<<( ostream& stream, const Contact& contact){
    stream << "Name: " << contact.getName() << endl;
    stream << "   Numbers: " << endl;
    for (size_t i = 0; i < contact.getNums().size(); ++i)
    {
        stream << "    " <<  i+1 << ") " << contact.getNums().at(i) << endl;
    }

    return stream;
}

#endif // CONTACT_H
