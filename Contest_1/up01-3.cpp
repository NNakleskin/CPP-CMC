#include <cstdio>
#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;


int main() {
    cin.tie(nullptr);
    bool indicate = false;
    bool is_a_num = false;
    char a;
    while(cin.get(a)) {
        if((a > '9' || a < '0') && indicate == false) {
            is_a_num = false;
            cout << a;
            continue;
        } else  if((a > '9' || a < '0') && indicate == true) {
            is_a_num = false;
            indicate = false;
            cout << '0';
            cout << a; 
            continue;
        } else if (a == '0' && is_a_num == false) {
            indicate = true;
            continue;
        } else if(a >= '0' && a <= '9') {
            is_a_num = true;
            indicate = false;
            cout << a;
            continue;
        }
    }
    if(indicate == true) {
        cout << '0';
    }
    fflush(stdout);
    return 0;
}
