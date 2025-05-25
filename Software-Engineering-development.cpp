#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

#include "SignUpUI.h"
#include "LoginUI.h"
#include "LogoutUI.h"
#include "AddBicycleUI.h"
//#include "RentalUI.h"

using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::array;

// --- 각 기능을 담당할 가짜 함수들 ---
bool handleSignUp(const string& id, const string& password, const string& phoneNumber) {
    // 회원가입 로직...
    //return { id, pw, phone};
    return true;
}
bool handleLogin(const string& id, const string& password) {
    // 로그인 로직...
    return true;
}
bool handleLogout(const string& id) {
    // 로그아웃 로직...
    //return Id (string)
    return true;
}
bool handleAddBicycle(const string& bicycleId, const string& bicycleName) {
    // 자전거 등록 로직...
    return true;
}
vector<pair<int,string>> handleLendBicycle(const string& bicycleId) {
    // 자전거 대여 로직...
    return { {1, "id"} };
}
vector<pair<int,string>> handleShowLendInfo() {
    // 대여 리스트 반환...
    //return {};
    return { {1, "id"} };
}

// --- 메인 처리 루프 ---
int main() {

    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "입력 파일을 열 수 없습니다.\n";
        return 1;
    }

    ofstream out("output.txt");
    if (!out.is_open()) {
        cout << "출력 파일을 열 수 없습니다.\n";
        return 1;
    }

    string line;
    while (std::getline(in, line)) {
        istringstream iss(line);
        int menu, action;
        // 아이디, 비밀번호, 전화번호, 자전거명 등을 담을 변수
        string id, pw, phone, bicycleId, bicycleName;

        // 먼저 메뉴와 액션만 뽑아보고
        if (!(iss >> menu >> action)) {
            // 숫자 두 개 못 읽으면 무시
            continue;
        }

        // 각 케이스별로 필요한 토큰을 한 번에 읽는다
        switch (menu) {
            case 1:
                if (action == 1) {
                    // 1.1 회원가입: "1 1 ID PW phone"
                    if (iss >> id >> pw >> phone) {
                        if(SignUpUI::handleSignUp(id, pw, phone)){
                            out << "1.1. 회원가입\n";
                            out << "> " << id << " " << pw << " " << phone << "\n\n";
                        }
                    }  
                }
                break;

            case 2:
                if (action == 1) {
                    // 2.1 로그인: "2 1 ID PW"
                    if (iss >> id >> pw) {
                        if(LoginUI::handleLogin(id, pw)){
                            out << "2.1. 로그인\n";
                            out << "> " << id << " " << pw << "\n\n";
                        }
                    }
                }
                else if (action == 2) {
                    // 2.2 로그아웃: "2 2"
                    string logoutId = LogoutUI::handleLogout();
                    if(!logoutId.empty()){
                        out << "2.2. 로그아웃\n";
                        out << "> " << logoutId << "\n\n";
                    }
                }
                break;

            case 3:
                if (action == 1) {
                    // 3.1 자전거 등록: "3 1 bicycleId bicycleName"
                    if (iss >> bicycleId >> bicycleName) {
                        if(AddBicycleUI::handleAddNewBicycle(bicycleId, bicycleName)){
                            out << "3.1. 자전거 등록\n";
                            out << "> " << bicycleId << " " << bicycleName << "\n\n";
                        }
                    }
                }
                break;

            case 4:
                if (action == 1) {
                    // 4.1 자전거 대여: "4 1 bicycleId"
                    if (iss >> bicycleId) {
                        auto result = handleLendBicycle(bicycleId); // bicycleId, bicycleName 두 값 받아와야함
                        
                        if(!result.empty()){
                            out << "4.1. 자전거 대여\n";
                            out << "> " << result[0].first << " " << result[0].second << "\n\n";
                        }
                    }
                }
                break;

            case 5:
                if (action == 1) {
                    // 5.1 대여 리스트: "5 1"
                    auto list = handleShowLendInfo();
                    out << "5.1. 자전거 대여 리스트\n";
                    for (auto& [id,name] : list) {
                        out << ">"; 
                        out << " " << id << " " << name << "\n\n";
                    }
                }
                    //반환 값 없으면 5.1 만 출력?
                break;

            case 6:
                if (action == 1) {
                    // 6.1 종료: "6 1"
                    out << "6.1. 종료\n";
                    return 0; //완전 실행 종료
                }
                break;

            // 그 외 메뉴/액션은 모두 무시
            default:
                break;
        }
    }

    in.close();
    out.close();
    return 0;
}