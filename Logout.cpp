#include "Logout.h"
#include "LoginUser.h"

string Logout::logout() {
    // 현재 로그인된 사용자의 ID 확인
    return LoginUser::deleteLoginUser();
}