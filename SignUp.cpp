#include "SignUp.h"
#include "Member.h"

bool SignUp::signUp(const string& id, const string& password, const string& phoneNumber) {
    return Member::addNewMember(id, password, phoneNumber);
}
