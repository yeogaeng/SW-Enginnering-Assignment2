#include "Member.h"
#include "RentalCollection.h"

using std::vector;
using std::string;

// static 멤버 초기화
int Member::nextMemberNum = 1;
vector<Member*> Member::memberList;

// 관리자 계정 자동 등록용 static 초기자
namespace {
    struct MemberInitializer {
        MemberInitializer() {
            Member::addNewMember("admin", "admin", "");
        }
    };
    static MemberInitializer _memberInit;
}


/*로그인*/
//회원인지 아이디, 비번 확인
int Member::isMember(const string& id, const string& password) {
    for (auto* m : memberList) {
        if (m->id == id && m->password == password)
            return m->memberNum;
    }
    return -1;
}

/*회원가입*/
//회원 추가
bool Member::addNewMember(const string& id, const string& password, const string& phoneNumber) {
    if(validateId(id)){
        Member* m = new Member(nextMemberNum++, id, password, phoneNumber);
        memberList.push_back(m);
        return true;
    }
    return false;
}

//id 중복 확인. true 여야 회원가입 가능
bool Member::validateId(const string& id) {
    for (auto* m : memberList) {
        if (m->id== id)
            return false;
    }
    return true;
}

// private 생성자
Member::Member(int memberNum, const string& id, const string& password, const string& phoneNumber)
    : memberNum(memberNum), id(id), password(password), phoneNumber(phoneNumber) {
    ownedRentalCollection = new RentalCollection();
}


Member* Member::findMemberByMemberNum(const int memberNum) {
    for (auto* m : memberList) {
        if (m->memberNum == memberNum)
            return m;
    }
    return nullptr;
}

// 회원 ID로 조회
Member* Member::findMemberById(const string& id) {
    for (auto* m : memberList) {
        if (m->id == id)
            return m;
    }
    return nullptr;
}


int Member::getMemberNum() const {
    return memberNum;
}

string Member::getId() const {
    return id;
}

string Member::getPhoneNumber() const {
    return phoneNumber;
}

RentalCollection* Member::getRentalCollection() const {
    return ownedRentalCollection;
}
