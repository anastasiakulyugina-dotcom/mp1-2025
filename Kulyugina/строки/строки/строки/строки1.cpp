#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "123oooeq777vkh efeiw53";
    int count = 0;

    for (char c : s) {
        if (isdigit(c)) {
            count++;
        }
    }

    /*
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count++;
        }
    }
*/
    cout << count << endl;
    return 0;
}