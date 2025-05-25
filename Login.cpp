#include "Login.h"
#include "LoginUser.h"
#include "Member.h"
#include <vector>
#include <utility>
#include <string>

using std::vector;
using std::pair;
using std::string;

//로그인
bool Login::login(const string& id, const string& password) { //1.1
    if (LoginUser::whoIsLogin().empty()) {//현재 아무도 로그인 중이 아닌지 확인 //1.1.1
        int memberNum = Member::isMember(id,password); //1.1.2
        if (memberNum){ //등록된 회원 맞는지 확인. 맞으면 회원번호 반환. 틀리면 -1
            return LoginUser::addLoginUser(memberNum, id); //1.1.3
        }
    }
    return false;
}

//로그인 외의 기능에서 로그인 중인지만 확인
bool Login::isLogin() {
    if (LoginUser::whoIsLogin().empty())
        return false;
    return true;
}
