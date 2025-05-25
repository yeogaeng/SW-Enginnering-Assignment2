#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

// Forward declaration
class RentalCollection;

class Member {
private:
    // 다음 회원 번호 발급기
    static int nextMemberNum;

    // 전체 회원 리스트
    static vector<Member*> memberList;

    int memberNum;
    string id;
    string password;
    string phoneNumber;
    // 이 회원이 가진 rental 컬렉션
    RentalCollection* ownedRentalCollection;

    // private 생성자: static factory만 사용
    Member(int memberNum, const string& id, const string& password, const string& phoneNumber);
    // ID 중복 확인: true면 중복 없음
    static bool validateId(const string& id);

public:
    static int isMember(const string& id, const string& password); // ID/PW로 기존 회원 검증
    static bool addNewMember(const string& id, const string& password, const string& phoneNumber); // 신규 회원 생성 및 리스트에 추가
    // 회원 번호로 조회
    static Member* findMemberByMemberNum(const int memberNum);
    
    int getMemberNum() const;
    string getId() const;
    string getPhoneNumber() const;
    RentalCollection* getRentalCollection() const;
};

#endif // MEMBER_H
