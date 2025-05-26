// ShowLendInfo.cpp
#include "ShowLendInfo.h"
#include "LoginUser.h"
#include "RentalCollection.h"
#include "Rental.h"
#include "Bicycle.h"
#include <algorithm>

ShowLendInfo::ShowLendInfo(LoginUser& session)
  : session(session)
{}

vector<pair<string,string>> ShowLendInfo::showLendInfo() {
    vector<pair<string,string>> result;

    // 1) 로그인된 Member* 얻기
    Member* m = session.whoIsLogin();
    if (!m) return result;

    // 2) RentalCollection* 순회
    RentalCollection* rc = m->getRentalCollection();
    Rental* r = rc->findFirst();
    while (r) {
        Bicycle* b = r->getBicycle();
        result.emplace_back(b->getId(), b->getName());
        r = rc->getNext();
    }

    // 3) ID 오름차순 정렬
    std::sort(result.begin(), result.end(), [](auto& a, auto& b){ return a.first < b.first; });

    return result;
}