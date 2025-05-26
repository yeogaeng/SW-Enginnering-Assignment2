// LendBicycle.h
#pragma once

#include <string>
#include <utility>
#include "BicycleRepository.h"
#include "MemberRepository.h"
#include "LoginUser.h"

using std::string;
using std::pair;

// <<control>> LendBicycle: 자전거 대여 로직 담당
// 성공 시 {bicycleId, bicycleName}, 실패 시 {"",""}
class LendBicycle {
private:
    BicycleRepository& bicycleRepository;
    MemberRepository& memberRepository;
    LoginUser& session;

public:
    // Repository들과 Session을 생성자 주입
    LendBicycle(BicycleRepository& bicycleRepository, MemberRepository& memberRepository, LoginUser& session);

    // 자전거 대여: 성공하면 {id,name}, 실패하면 {"",""}
    pair<string,string> lendBicycle(string bicycleId);
};