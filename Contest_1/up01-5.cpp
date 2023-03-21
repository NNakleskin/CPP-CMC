#include <iostream>
#include <climits>
#include <cstring>
#include <bits/stdc++.h>


int main () {
    std::string res_number;
    std::string buf;
    int count = 0;
    while (std::cin >> buf) {
        if (buf.length () != 2) {
            buf.clear ();
            res_number.clear ();
            count = 0;
            continue;
        }
        if (count < 4) {
            count++;
            res_number += buf;
        }
        if (count == 4) {
            unsigned int res;
            std::istringstream s (res_number);
            s >> std::hex >> res;
            std::cout << res << std::endl;
            count = 0;
            res_number.clear ();
        }
        buf.clear ();
    }
}