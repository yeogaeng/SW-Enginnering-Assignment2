// Login.h
#pragma once

#include <string>
#include "MemberRepository.h"
#include "LoginUser.h"

using std::string;

// 로그인 기능을 위한 Login 클래스 정의
class Login {
private:
    MemberRepository& memberRepository;     // 회원 정보를 관리하는 Repository 참조
    LoginUser& session;                     // 현재 로그인 세션 정보를 관리하는 객체 참조
    
public:
    /*
        함수 이름 : Login::Login()
        기능      : Login 클래스의 생성자로, MemberRepository와 LoginUser 참조를 초기화함
        전달 인자 : MemberRepository& memoryRepository - 회원 정보를 관리하는 Repository 객체의 참조
                   LoginUser& session - 로그인 세션 정보를 관리하는 객체의 참조
        반환값    : 없음
    */
    Login(MemberRepository& memoryRepository, LoginUser& session);

    /*
        함수 이름 : Login::login()
        기능      : ID와 비밀번호를 검증하여 로그인을 처리하고 세션에 정보를 저장함
        전달 인자 : string id - 회원 ID
                   string password - 회원 비밀번호
        반환값    : bool -> 로그인 성공 시 true, 실패 시 false
    */
    bool login(string id, string password);
};