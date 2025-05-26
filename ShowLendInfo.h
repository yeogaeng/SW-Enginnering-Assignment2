// ShowLendInfo.h
#pragma once

#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::pair;
using std::string;

class LoginUser;

// <<control>> ShowLendInfo: 대여 정보 조회 로직 담당
class ShowLendInfo {
private:
    LoginUser& session;

public:
    // Session을 생성자 주입
    ShowLendInfo(LoginUser& session);

    // 로그인된 회원의 대여 리스트 반환
    // {bicycleId, bicycleName} 쌍의 벡터
    vector<pair<string,string>> showLendInfo();
};