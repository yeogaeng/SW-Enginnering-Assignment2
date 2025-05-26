// MemberRepository.cpp
#include "MemberRepository.h"
#include <algorithm>

/*
    함수 이름 : MemberRepository::MemberRepository()
    기능      : MemberRepository 클래스의 생성자로, 회원 번호 발급기를 1번부터 시작하도록 초기화함
    전달 인자 : 없음
    반환값    : 없음
*/
MemberRepository::MemberRepository()
  : nextMemberNum(1)
{}

/*
    함수 이름 : MemberRepository::~MemberRepository()
    기능      : MemberRepository 클래스의 소멸자로, 동적 할당된 Member 객체들의 메모리를 해제함
    전달 인자 : 없음
    반환값    : 없음
*/
MemberRepository::~MemberRepository() {
    for (auto* m : members) {
        delete m;
    }
}

/*
    함수 이름 : MemberRepository::addNewMember()
    기능      : 신규 회원을 추가함
    전달 인자 : string id - 회원 ID
               string password - 회원 비밀번호
               string phoneNumber - 회원 전화번호
    반환값    : Member* -> 생성된 회원 객체의 포인터, 중복 ID인 경우 nullptr
*/
Member* MemberRepository::addNewMember(string id, string password,string phoneNumber) {
    // 중복 ID 검사
    if (findMemberById(id) != nullptr)
        return nullptr;
    // Member 객체 생성 및 저장
    Member* m = new Member(nextMemberNum++, id, password, phoneNumber);
    members.push_back(m);
    return m;
}

/*
    함수 이름 : MemberRepository::authenticate()
    기능      : ID와 비밀번호를 검증하여 회원 인증을 수행함
    전달 인자 : string id - 회원 ID
               string password - 회원 비밀번호
    반환값    : Member* -> 인증된 회원 객체의 포인터, 인증 실패 시 nullptr
*/
Member* MemberRepository::authenticate(string id, string password){
    for (auto* m : members) {
        // checkPassword()를 이용해 비밀번호 검증
        if (m->getId() == id && m->checkPassword(password)) {
            return m;  // 인증 성공
        }
    }
    return nullptr;  // 인증 실패
}

/*
    함수 이름 : MemberRepository::findMemberById()
    기능      : ID로 회원을 조회함
    전달 인자 : string id - 조회할 회원 ID
    반환값    : Member* -> 찾은 회원 객체의 포인터, 없으면 nullptr
*/
Member* MemberRepository::findMemberById(string id){
    for (auto* m : members) {
        if (m->getId() == id) {
            return m;
        }
    }
    return nullptr;
}