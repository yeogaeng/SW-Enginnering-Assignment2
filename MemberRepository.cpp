// MemberRepository.cpp
#include "MemberRepository.h"
#include <algorithm>

// 생성자: nextMemberNum을 1로 초기화
MemberRepository::MemberRepository()
  : nextMemberNum(1)
{}

// 소멸자: 등록된 Member 인스턴스 메모리 해제
MemberRepository::~MemberRepository() {
    for (auto* m : members) {
        delete m;
    }
}

// 신규 회원 추가
Member* MemberRepository::addNewMember(string id, string password,string phoneNumber) {
    // 중복 ID 검사
    if (findMemberById(id) != nullptr) {
        return nullptr;
    }
    // Member 객체 생성 및 저장
    Member* m = new Member(nextMemberNum++, id, password, phoneNumber);
    members.push_back(m);
    return m;
}

// ID/PW 검증
Member* MemberRepository::authenticate(string id, string password){
    for (auto* m : members) {
        // checkPassword()를 이용해 비밀번호 검증
        if (m->getId() == id && m->checkPassword(password)) {
            return m;  // 인증 성공
        }
    }
    return nullptr;  // 인증 실패
}

// ID로 회원 조회
Member* MemberRepository::findMemberById(string id){
    for (auto* m : members) {
        if (m->getId() == id) {
            return m;
        }
    }
    return nullptr;
}