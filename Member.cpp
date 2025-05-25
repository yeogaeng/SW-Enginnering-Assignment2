#include "Member.h"
#include "RentalCollection.h"

using std::vector;
using std::string;

// private 생성자
Member::Member(int memberNum, string& id, string& password, string& phoneNumber)
    : memberNum(memberNum), id(id), password(password), phoneNumber(phoneNumber), ownedRentalCollection(new RentalCollection()) {
}

string Member::getId(){
    return id;
}

string Member::getPhoneNumber(){
    return phoneNumber;
}

bool Member::checkPassword(string& password){
    if(this->password == password)
        return true;
    return false;
}

RentalCollection* Member::getRentalCollection(){
    return ownedRentalCollection;
}

