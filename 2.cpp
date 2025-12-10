#include <iostream>
#include <windows.h>
#include <string>
#include <cctype>
using namespace std;


bool validatePassword(string password) {

    int len = password.length();
    if (len < 8 || len > 14) {
        cout << "oshibka: nevernaya dlina (nujno 8-14, u vas " << len << ")" << endl;
        return false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasOther = false;

    for (char c : password) {

        if (static_cast<int>(c) < 33 || static_cast<int>(c) > 126) {
            cout << "oshibka: nedopustimiy simvol '" << c << "'" << endl;
            return false;
        }

        if (isupper(c)) {
            hasUpper = true;
        } else if (islower(c)) {
            hasLower = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        } else {

            hasOther = true;
        }
    }


    int classCount = 0;
    if (hasUpper) classCount++;
    if (hasLower) classCount++;
    if (hasDigit) classCount++;
    if (hasOther) classCount++;
    if (classCount < 3) {
        cout << "v parole nuzhno ispolzovat 3 iz 4 klassov: bolshyu, malenkyu bykvy, cifry, spec simvol " << endl;
        return false;
    }

    return true;
}

int main() {

    string line;
    cout << "vvedite parol: " << endl;
    getline(cin, line);
    cout << "---------------------------------" << endl;
    if (validatePassword(line)) {
        cout << "parol podhodit" << endl;
    } else {
        cout << "parol ne podhodit" << endl;
    }

    return 0;
}
