// ShowLendInfoUI.cpp
#include "ShowLendInfoUI.h"

ShowLendInfoUI::ShowLendInfoUI(ShowLendInfo& ctrl)
  : showCtrl(ctrl)
{}

vector<pair<string,string>> ShowLendInfoUI::handleShowLendInfo() {
    return showCtrl.showLendInfo();
}