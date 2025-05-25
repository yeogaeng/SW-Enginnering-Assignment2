// Logout.h
#pragma once

#include <string>
#include "LoginUser.h"

using std::string;

// <<control>> Logout: 로그아웃 비즈니스 로직 담당
class Logout {
private:
    LoginUser& session;

public:
    // 세션 객체를 생성자 주입
    Logout(LoginUser& session);

    // 로그아웃 시도: 성공하면 이전 로그인 ID 반환, 실패 시 빈 문자열
    string handleLogout();
};