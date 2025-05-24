#include "LoginUser.h"
#include <string>

using std::string;

// static 멤버 초기화
int LoginUser::sessionNum = -1;
string LoginUser::sessionId = "";

bool LoginUser::addLoginUser(int memberNum, const std::string& id) {
    if (sessionNum != -1) 
        return false; // 이미 로그인 중
    
    sessionNum = sessionNum;
    sessionId = id;
    return true;
}

bool LoginUser::deleteLoginUser() {
    if (sessionNum == -1) 
        return false; // 로그인 상태 아님
    
    sessionNum = -1;
    sessionId.clear();
    return true;
}

bool LoginUser::isLogin() {
    if(sessionNum != -1)
        return true; // 이미 로그인 중
    
    return false;
}

int LoginUser::getSessionNum() {
    return sessionNum;
}

std::string LoginUser::getSessionId() {
    return sessionId;
}