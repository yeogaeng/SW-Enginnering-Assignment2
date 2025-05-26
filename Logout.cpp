// Logout.cpp
#include "Logout.h"
#include "LoginUser.h"

/*
    함수 이름 : Logout::Logout()
    기능      : Logout 클래스의 생성자로, LoginUser 참조를 초기화함
    전달 인자 : LoginUser& session - 로그인 세션 정보를 관리하는 객체의 참조
    반환값    : 없음
*/
Logout::Logout(LoginUser& session)
  : session(session)
{}

/*
    함수 이름 : Logout::logout()
    기능      : 현재 로그인된 사용자를 로그아웃 처리함
    전달 인자 : 없음
    반환값    : string -> 로그아웃된 사용자의 ID, 로그아웃 실패 시 빈 문자열
*/
string Logout::logout() {
    // 현재 로그인된 회원 가져오기
    Member* m = session.whoIsLogin();
    if (m) {
        string id = m->getId();
        session.deleteLoginUser();  // 세션에서 로그인 정보 삭제
        return id;
    }
    return "";  // 로그인된 사용자가 없는 경우
}