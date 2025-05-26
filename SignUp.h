// SignUp.h
#pragma once

#include <string>
#include "MemberRepository.h"

using std::string;

// 회원가입 기능을 위한 SignUp 클래스 정의
class SignUp {
private:
    MemberRepository& memberRepository;     // 회원 정보를 관리하는 Repository 참조

public:
    /*
        함수 이름 : SignUp::SignUp()
        기능      : SignUp 클래스의 생성자로, MemberRepository 참조를 초기화함
        전달 인자 : MemberRepository& memberRepository - 회원 정보를 관리하는 Repository 객체의 참조
        반환값    : 없음
    */
    SignUp(MemberRepository& memberRepository);

    /*
        함수 이름 : SignUp::signUp()
        기능      : 신규 회원을 등록함
        전달 인자 : string id - 회원 ID
                   string password - 회원 비밀번호
                   string phoneNumber - 회원 전화번호
        반환값    : bool -> 회원가입 성공 시 true, 실패 시 false
    */
    bool signUp(string id, string password, string phoneNumber);
};