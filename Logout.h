#pragma once
#include <string>

using std::string;

// <<control>> Logout: 로그아웃 비즈니스 로직
class Logout {
public:
    // 로그아웃 시도: 성공하면 sessionId 반환, 실패 시 빈 문자열
    static string logout();
};
