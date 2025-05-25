// LogoutUI.h
#pragma once

#include <string>
#include "Logout.h"

using std::string;

// <<boundary>> LogoutUI: 파싱된 입력을 받아 로그아웃 컨트롤 호출
class LogoutUI {
private:
    Logout& logoutCtrl;

public:
    // Logout 컨트롤러를 생성자 주입
    LogoutUI(Logout& ctrl);

    // 로그아웃 처리, 반환값은 로그아웃된 ID 또는 빈 문자열
    string handleLogout();
};