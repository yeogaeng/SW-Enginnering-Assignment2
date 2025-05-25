#include "SignUpUI.h"
#include "SignUp.h"

bool SignUpUI::handleSignUp(const string& id, const string& password, const string& phoneNumber) {
    return SignUp::signUp(id, password, phoneNumber);
}
