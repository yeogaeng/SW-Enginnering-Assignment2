#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "RentalCollection.h"

using std::string;
using std::vector;

class Member {
private:
    int memberNum;
    string id;
    string password;
    string phoneNumber;
    // 이 회원이 가진 rental 컬렉션
    RentalCollection* ownedRentalCollection;

public:
    Member(int memberNum, string& id, string& password, string& phoneNumber); //repo에서 호출
    int getMemberNum();
    string getId();
    string getPhoneNumber();
    bool checkPassword(string& passsword);

    RentalCollection* getRentalCollection();
};

#endif // MEMBER_H
