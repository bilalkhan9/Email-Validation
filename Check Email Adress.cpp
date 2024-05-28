#include <iostream>
using namespace std;

bool IsValidEmailId(char *);

int main() {
    char email[100];
    cout << "Enter Email Id" << endl;
    cin.get(email, 100);
    try {
        if (IsValidEmailId(email))
            cout << "Valid Email Id" << endl;
        else
            throw 'c';
    }
    catch (char c) {
        cout << "Exception: Invalid Email Id !!!" << endl;
    }
    catch (...) {
        cout << "Default Exception" << endl;
    }
    system("pause");
   return 0;
}

bool IsValidEmailId(char *email) {
    int Atoffset = -1;
    int Dotoffset = -1;
    int length = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@')
            Atoffset = i;
        else if (email[i] == '.')
            Dotoffset = i;
        length++;
    }
    if (Atoffset == -1 || Dotoffset == -1)
        return false;
    if (Atoffset > Dotoffset)
        return false;
    return (Dotoffset < (length - 1));
}
