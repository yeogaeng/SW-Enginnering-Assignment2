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
        if (!Member::isMember(id,password).empty()) //1.1.2 등록된 회원 맞는지 확인. 맞으면 회원 아이디 반환. 틀리면 ""반환
            return LoginUser::addLoginUser(id); //1.1.3
    }
    return false;
}
