// SignUp.h
#pragma once

#include <string>
#include "MemberRepository.h"

using std::string;

// <<control>> SignUp: 회원가입 로직 담당
class SignUp {
private:
    MemberRepository& memberRepository;

public:
    // Repository를 생성자 주입
    SignUp(MemberRepository& memberRepository);

    // 신규 회원 등록: 성공(true)/실패(false)
    bool signUp(string id, string password, string phoneNumber);
};