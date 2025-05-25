// LogoutUI.cpp
#include "LogoutUI.h"

LogoutUI::LogoutUI(Logout& ctrl)
  : logoutCtrl(ctrl)
{}

string LogoutUI::handleLogout() {
    return logoutCtrl.handleLogout();
}