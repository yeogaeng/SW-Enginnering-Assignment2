#include "Login.h"
#include "LoginUser.h"
#include "Member.h"
#include <vector>
#include <utility>
#include <string>

using std::vector;
using std::pair;
using std::string;

bool Login::login(const string& id, const string& password) {
    if (!LoginUser::isLogin()) {//현재 아무도 로그인 중이 아닌지 확인
        int memberNum = Member::isMember(id,password);
        if (memberNum){ //등록된 회원 맞는지 확인. 맞으면 회원번호 반환. 틀리면 -1
            LoginUser::addLoginUser(memberNum, id);
            return true;
        }
    }
    return false;
}

bool Login::isLogin() {
    return LoginUser::isLogin();
}