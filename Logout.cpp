// Logout.cpp
#include "Logout.h"
#include "LoginUser.h"

Logout::Logout(LoginUser& session)
  : session(session)
{}

string Logout::handleLogout() {
    // 현재 로그인된 회원 가져오기
    Member* m = session.whoIsLogin();
    if (m) {
        string id = m->getId();
        session.deleteLoginUser();
        return id;
    }
    return "";
}