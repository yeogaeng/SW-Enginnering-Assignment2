#include "ShowLendInfo.h"
#include "LoginUser.h"
#include "Member.h"
#include "RentalCollection.h"
#include "Rental.h"
#include "Bicycle.h" 
#include <algorithm>

vector<pair<string, string>> ShowLendInfo::showLendInfo() {

    vector<pair<string, string>> result;
    
    // 1) 로그인된 회원 ID 확인
    string memberId = LoginUser::whoIsLogin();
    if (memberId.empty())
        return result;

    // 2) 회원 객체 조회
    Member* m = Member::findMemberById(memberId);
    if (!m)
        return result;

    // 3) RentalCollection 순회하여 자전거 ID/이름 수집
    RentalCollection* rc = m->getRentalCollection();
    Rental* r = rc->findFirst();
    while (r) {
        Bicycle* b = r->getBicycle();
        result.emplace_back(b->getId(), b->getName());
        r = rc->getNext();
    }

    // 4) 자전거 ID 오름차순 정렬
    std::sort(result.begin(), result.end(),
              [](const pair<string,string>& a, const pair<string,string>& b) {
                  return a.first < b.first;
              });

    return result;
}
