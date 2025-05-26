// ShowLendInfo.cpp
#include "ShowLendInfo.h"
#include "LoginUser.h"
#include "RentalCollection.h"
#include "Rental.h"
#include "Bicycle.h"
#include <algorithm>

/*
    함수 이름 : ShowLendInfo::ShowLendInfo()
    기능      : ShowLendInfo 클래스의 생성자로, LoginUser 참조를 초기화함
    전달 인자 : LoginUser& session - 로그인 세션 정보를 관리하는 객체의 참조
    반환값    : 없음
*/
ShowLendInfo::ShowLendInfo(LoginUser& session)
  : session(session)
{}

/*
    함수 이름 : ShowLendInfo::showLendInfo()
    기능      : 로그인된 회원의 대여 정보 리스트를 조회함
    전달 인자 : 없음
    반환값    : vector<pair<string,string>> -> {자전거ID, 자전거이름} 쌍의 벡터
*/
vector<pair<string,string>> ShowLendInfo::showLendInfo() {
    vector<pair<string,string>> result;

    // 로그인된 회원 정보 가져오기
    Member* m = session.whoIsLogin();
    if (!m) return result;  // 로그인되지 않은 경우 빈 벡터 반환

    // 회원의 대여 컬렉션 순회
    RentalCollection* rc = m->getRentalCollection();
    Rental* r = rc->findFirst();
    while (r) {
        Bicycle* b = r->getBicycle();
        result.emplace_back(b->getId(), b->getName());
        r = rc->getNext();
    }

    // 자전거 ID 기준 오름차순 정렬
    std::sort(result.begin(), result.end(), [](auto& a, auto& b){ return a.first < b.first; });

    return result;
}