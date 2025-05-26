#pragma once

#include "Member.h"

// 현재 로그인 세션을 관리하는 LoginUser 클래스 정의
class LoginUser {
private:
    Member* currentMember;      // 현재 로그인된 회원을 가리키는 포인터 (nullptr이면 로그아웃 상태)

public:
    /*
        함수 이름 : LoginUser::LoginUser()
        기능      : LoginUser 클래스의 생성자로, 초기에는 아무도 로그인되어 있지 않은 상태로 초기화함
        전달 인자 : 없음
        반환값    : 없음
    */
    LoginUser();

    /*
        함수 이름 : LoginUser::addLoginUser()
        기능      : 회원을 로그인 상태로 설정함
        전달 인자 : Member* member - 로그인할 회원 객체의 포인터
        반환값    : bool -> 로그인 성공 시 true, 실패 시 false (이미 다른 사용자가 로그인 중이거나 member가 nullptr인 경우)
    */
    bool addLoginUser(Member* member);

    /*
        함수 이름 : LoginUser::deleteLoginUser()
        기능      : 현재 로그인된 회원을 로그아웃 처리함
        전달 인자 : 없음
        반환값    : 없음
    */
    void deleteLoginUser();

    /*
        함수 이름 : LoginUser::whoIsLogin()
        기능      : 현재 로그인 중인 회원 정보를 반환함
        전달 인자 : 없음
        반환값    : Member* -> 로그인 중인 회원 객체의 포인터 (로그아웃 상태면 nullptr)
    */
    Member* whoIsLogin();
};