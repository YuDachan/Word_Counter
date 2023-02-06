#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void lswap(char *str,char *cstr, char c, char r) {
    for (int i = 0; i <= strlen(str); i++) {
        if (isupper(str[i-1]) == toupper(r)) {
            str[i-1] = toupper(r);
        }
        if (str[i-1] == c) {
            str[i-1] = r;
        }
    }
    strcpy(cstr, str);
}

int main() {
    char cstr[1023], str[1023];
    char c, r;

    cin.getline(str, 1023);
    cout << "letter search ";
    cin >> c;
    cout << endl;
    cout << "letter replace ";
    cin >> r;

    lswap(str, cstr, c, r);

    cout << endl;
    cout << str << endl;
    cout << cstr << endl;

    return 0;
}