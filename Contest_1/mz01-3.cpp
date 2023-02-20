#include <cstdio>
#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;


int main() {
    cin.tie(NULL);
    bool indicate = false;
    
    char a, b;
    cin >> a;
    
    while(cin >> b) {
        if(a > '0' && a <= '9') {
            indicate = true;
        } else if(a != '0') {
            indicate = false;
        } else {
            cout << '0';
        }
        if(a == '0' && b > '0' && b <= '9' && indicate == false) {
            a = b;
            continue;
        } else if(a == '0' && b == '0' && indicate == false) {
            a = b;
            continue;
        } else {
            cout << a;
        }
        a = b;
    }
    cout << endl;
    return 0;
}

