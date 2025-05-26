#include "Member.h"
#include "RentalCollection.h"

using std::vector;
using std::string;

/*
    함수 이름 : Member::Member()
    기능      : Member 클래스의 생성자로, 회원 정보를 초기화하고 대여 컬렉션을 생성함
    전달 인자 : int memberNum - 회원 번호
               string& id - 회원 ID
               string& password - 회원 비밀번호
               string& phoneNumber - 회원 전화번호
    반환값    : 없음
*/
Member::Member(int memberNum, string& id, string& password, string& phoneNumber)
    : memberNum(memberNum), id(id), password(password), phoneNumber(phoneNumber), ownedRentalCollection(new RentalCollection()) {
}

/*
    함수 이름 : Member::getId()
    기능      : 회원의 ID를 반환함
    전달 인자 : 없음
    반환값    : string -> 회원 ID
*/
string Member::getId(){
    return id;
}

/*
    함수 이름 : Member::getPhoneNumber()
    기능      : 회원의 전화번호를 반환함
    전달 인자 : 없음
    반환값    : string -> 회원 전화번호
*/
string Member::getPhoneNumber(){
    return phoneNumber;
}

/*
    함수 이름 : Member::checkPassword()
    기능      : 입력된 비밀번호가 회원의 비밀번호와 일치하는지 확인함
    전달 인자 : string& password - 확인할 비밀번호
    반환값    : bool -> 비밀번호가 일치하면 true, 일치하지 않으면 false
*/
bool Member::checkPassword(string& password){
    if(this->password == password)
        return true;
    return false;
}

/*
    함수 이름 : Member::getRentalCollection()
    기능      : 회원의 대여 정보 컬렉션을 반환함
    전달 인자 : 없음
    반환값    : RentalCollection* -> 대여 정보 컬렉션 포인터
*/
RentalCollection* Member::getRentalCollection(){
    return ownedRentalCollection;
}

