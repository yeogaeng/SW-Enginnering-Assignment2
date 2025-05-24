#include "LoginUI.h"
#include "Login.h"
#include <sstream>

using std::istringstream;
using std::vector;
using std::pair;
using std::string;

bool LoginUI::handleLogin(const string& id, const string& password) {
    return Login::login(id, password);
}