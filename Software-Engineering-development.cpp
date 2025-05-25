#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>


#include "SignUpUI.h"
#include "LoginUI.h"
#include "LogoutUI.h"
#include "AddBicycleUI.h"
#include "LendBicycleUI.h"
#include "ShowLendInfoUI.h" 

#include "SignUp.h"
#include "Login.h"
#include "Logout.h"
#include "AddBicycle.h"
#include "LendBicycle.h"
#include "ShowLendInfo.h" 

#include "MemberRepository.h"
#include "LoginUser.h"

using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::pair;

int main() {
    MemberRepository memberRepository;
    // 미리 관리자 등록
    memberRepository.addNewMember("admin","admin","");
    LoginUser session;
    BicycleRepository bicycleRepository;

    // 2) Controller 만들기 (비즈니스 로직)
    SignUp      signUpCtrl(memberRepository);
    Login       loginCtrl(memberRepository, session);
    Logout      logoutCtrl(session);
    AddBicycle  addBicycleCtrl(bicycleRepository);
    LendBicycle lendBicycleCtrl(bicycleRepository, memberRepository, session);
    ShowLendInfo showLendCtrl(session);

    // 3) UI 만들기 (입력/출력 어댑터)
    SignUpUI       signUpUI(signUpCtrl);
    LoginUI        loginUI(loginCtrl);
    LogoutUI       logoutUI(logoutCtrl);
    AddBicycleUI   addBicycleUI(addBicycleCtrl);
    LendBicycleUI  lendBicycleUI(lendBicycleCtrl);
    ShowLendInfoUI showLendUI(showLendCtrl);

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
                        if(signUpUI.handleSignUp(id, pw, phone)){
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
                        if(loginUI.handleLogin(id, pw)){
                            out << "2.1. 로그인\n";
                            out << "> " << id << " " << pw << "\n\n";
                        }
                    }
                }
                else if (action == 2) {
                    // 2.2 로그아웃: "2 2"
                    string logoutId = logoutUI.handleLogout();
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
                        if(addBicycleUI.handleAddNewBicycle(bicycleId, bicycleName)){
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
                        auto result = lendBicycleUI.handleLendBicycle(bicycleId);
                        if (!result.first.empty() || !result.first.empty()) {
                            out << "4.1. 자전거 대여\n";
                            out << "> " << result.first << " " << result.second << "\n\n";
                        }
                    }
                }
                break;

            case 5:
                if (action == 1) {
                    // 5.1 대여 리스트: "5 1"
                    auto list = showLendUI.handleShowLendInfo();
                    out << "5.1. 자전거 대여 리스트\n";
                    for (auto& [id,name] : list) {
                        out << ">"; 
                        out << " " << id << " " << name << "\n";
                    }
                    out << "\n";
                }
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