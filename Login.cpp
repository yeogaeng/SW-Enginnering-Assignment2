// Login.cpp
#include "Login.h"

// 생성자: memberRepo 와 session 을 초기화
Login::Login(MemberRepository& repo, LoginUser& session)
  : memberRepository(repo), session(session)
{}

bool Login::login(string id, string password) {
    // 현재 아무도 로그인 중이 아니어야 함
    if (session.whoIsLogin() == nullptr) { // 인증된 Member* 반환, 실패 시 nullptr
        Member* m = memberRepository.authenticate(id, password);
        if (m) // 세션에 로그인 시도
            return session.addLoginUser(m);
    }
    return false;
}