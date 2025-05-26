#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "RentalCollection.h"

using std::string;
using std::vector;

// 회원 정보를 관리하는 Member 클래스 정의
class Member {
private:
    int memberNum;                              // 회원 번호
    string id;                                  // 회원 ID
    string password;                            // 회원 비밀번호
    string phoneNumber;                         // 회원 전화번호
    RentalCollection* ownedRentalCollection;    // 이 회원이 보유한 대여 정보 컬렉션

public:
    /*
        함수 이름 : Member::Member()
        기능      : Member 클래스의 생성자로, 회원 정보를 초기화함
        전달 인자 : int memberNum - 회원 번호
                   string& id - 회원 ID
                   string& password - 회원 비밀번호
                   string& phoneNumber - 회원 전화번호
        반환값    : 없음
    */
    Member(int memberNum, string& id, string& password, string& phoneNumber);

    /*
        함수 이름 : Member::checkPassword()
        기능      : 입력된 비밀번호가 회원의 비밀번호와 일치하는지 확인함
        전달 인자 : string& passsword - 확인할 비밀번호
        반환값    : bool -> 비밀번호가 일치하면 true, 일치하지 않으면 false
    */
    bool checkPassword(string& passsword);

    /*
        함수 이름 : Member::getId()
        기능      : 회원의 ID를 반환함
        전달 인자 : 없음
        반환값    : string -> 회원 ID
    */
    string getId();
    
    /*
        함수 이름 : Member::getPhoneNumber()
        기능      : 회원의 전화번호를 반환함
        전달 인자 : 없음
        반환값    : string -> 회원 전화번호
    */
    string getPhoneNumber();
    
    /*
        함수 이름 : Member::getRentalCollection()
        기능      : 회원의 대여 정보 컬렉션을 반환함
        전달 인자 : 없음
        반환값    : RentalCollection* -> 대여 정보 컬렉션 포인터
    */
    RentalCollection* getRentalCollection();
};

#endif // MEMBER_H
