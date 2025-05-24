#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

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
    Member(int num, const string& uid, const string& pw, const string& phone);

public:
    static bool isMember(const string& uid, const string& pw); // ID/PW로 기존 회원 검증
    static bool addNewMember(const string& uid, const string& pw, const string& phone); // 신규 회원 생성 및 리스트에 추가
    
    int getMemberNum() const;
    string getId() const;
    string getPhoneNumber() const;
};

#endif // MEMBER_H
