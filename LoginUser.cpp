// LoginUser.cpp
#include "LoginUser.h"

/*
    함수 이름 : LoginUser::LoginUser()
    기능      : LoginUser 클래스의 생성자로, 초기에는 아무도 로그인되어 있지 않은 상태로 초기화함
    전달 인자 : 없음
    반환값    : 없음
*/
LoginUser::LoginUser()
  : currentMember(nullptr)
{}

/*
    함수 이름 : LoginUser::addLoginUser()
    기능      : 회원을 로그인 상태로 설정함
    전달 인자 : Member* member - 로그인할 회원 객체의 포인터
    반환값    : bool -> 로그인 성공 시 true, 실패 시 false
*/
bool LoginUser::addLoginUser(Member* member) {
    // member가 nullptr이거나 이미 다른 사용자가 로그인된 상태면 실패
    if (!member || currentMember) {
        return false;
    }
    currentMember = member;
    return true;
}

/*
    함수 이름 : LoginUser::deleteLoginUser()
    기능      : 현재 로그인된 회원을 로그아웃 처리함
    전달 인자 : 없음
    반환값    : 없음
*/
void LoginUser::deleteLoginUser() {
    currentMember = nullptr;
}

/*
    함수 이름 : LoginUser::whoIsLogin()
    기능      : 현재 로그인 중인 회원 정보를 반환함
    전달 인자 : 없음
    반환값    : Member* -> 로그인 중인 회원 객체의 포인터 (로그아웃 상태면 nullptr)
*/
Member* LoginUser::whoIsLogin() {
    return currentMember;
}