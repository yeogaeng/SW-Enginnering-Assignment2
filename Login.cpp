// Login.cpp
#include "Login.h"

/*
    함수 이름 : Login::Login()
    기능      : Login 클래스의 생성자로, MemberRepository와 LoginUser 참조를 초기화함
    전달 인자 : MemberRepository& repo - 회원 정보를 관리하는 Repository 객체의 참조
               LoginUser& session - 로그인 세션 정보를 관리하는 객체의 참조
    반환값    : 없음
*/
Login::Login(MemberRepository& repo, LoginUser& session)
  : memberRepository(repo), session(session)
{}

/*
    함수 이름 : Login::login()
    기능      : ID와 비밀번호를 검증하여 로그인을 처리하고 세션에 정보를 저장함
    전달 인자 : string id - 회원 ID
               string password - 회원 비밀번호
    반환값    : bool -> 로그인 성공 시 true, 실패 시 false
*/
bool Login::login(string id, string password) {
    // 현재 아무도 로그인 중이 아니어야 함
    if (session.whoIsLogin() == nullptr) { 
        // ID와 비밀번호를 검증하여 인증된 Member 포인터 반환, 실패 시 nullptr
        Member* m = memberRepository.authenticate(id, password);
        if (m) // 인증 성공 시 세션에 로그인 정보 저장
            return session.addLoginUser(m);
    }
    return false;
}