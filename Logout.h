// Logout.h
#pragma once

#include <string>
#include "LoginUser.h"

using std::string;

// 로그아웃 기능을 위한 Logout 클래스 정의
class Logout {
private:
    LoginUser& session;     // 현재 로그인 세션 정보를 관리하는 객체 참조

public:
    /*
        함수 이름 : Logout::Logout()
        기능      : Logout 클래스의 생성자로, LoginUser 참조를 초기화함
        전달 인자 : LoginUser& session - 로그인 세션 정보를 관리하는 객체의 참조
        반환값    : 없음
    */
    Logout(LoginUser& session);

    /*
        함수 이름 : Logout::logout()
        기능      : 현재 로그인된 사용자를 로그아웃 처리함
        전달 인자 : 없음
        반환값    : string -> 로그아웃된 사용자의 ID, 로그아웃 실패 시 빈 문자열
    */
    string logout();
};