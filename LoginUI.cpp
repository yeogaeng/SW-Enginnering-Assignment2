// LoginUI.cpp
#include "LoginUI.h"

// 생성자: loginCtrl 초기화
LoginUI::LoginUI(Login& ctrl)
  : loginCtrl(ctrl)
{}

bool LoginUI::handleLogin(string id, string password) {
    return loginCtrl.login(id, password);
}