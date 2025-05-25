#pragma once

#include "Member.h"

class LoginUser {
private:
    // 현재 로그인된 회원을 가리키는 포인터 (nullptr 이면 로그아웃 상태)
    Member* currentMember;

public:
    // 생성자: 초기에는 아무도 로그인되어 있지 않음
    LoginUser();

    // 로그인: m 이 nullptr 이거나 이미 다른 사용자가 로그인 중이면 실패
    bool addLoginUser(Member* member);

    // 로그아웃: 언제나 성공, session 해제
    void deleteLoginUser();

    // 지금 로그인 중인 Member* 반환 (nullptr 이면 로그아웃 상태)
    Member* whoIsLogin();
};