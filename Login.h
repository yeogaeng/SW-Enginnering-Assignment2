// Login.h
#pragma once

#include <string>
#include "MemberRepository.h"
#include "LoginUser.h"

using std::string;

// <<control>> Login: 로그인 로직 담당
class Login {
private:
    MemberRepository& memberRepo;
    LoginUser&       session;
public:
    // Repository 과 Session 을 생성자 주입
    Login(MemberRepository& repository, LoginUser& session);

    // ID/PW 검증 후 세션에 로그인, 성공 시 true
    bool handleLogin(string id, string password);
};