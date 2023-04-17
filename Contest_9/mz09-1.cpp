#include <iostream>
#include <string>
#include <algorithm>


bool is_alpha (std::string str) {
    if (str.empty ()) {
        return true;
    }
    if (str[0] == '3' || str[0] == '4') {
        return is_alpha (str.substr (1));
    }
    return false;
}

bool is_beta (std::string str) {
    if (str.empty ()) {
        return true;
    }
    if (str[0] == '1' || str[0] == '2') {
        return is_beta (str.substr (1));
    }
    return false;
}

bool parse_str (std::string str) {
    size_t i = 0;
    while (i < str.length () && (str[i] == '3' || str[i] == '4')) {
        i++;
    }
    return is_alpha (str.substr (0, i)) && is_beta (str.substr (i));
}

int main () {
    std::string str;
    while (std::cin >> str) {
        std::cout << parse_str (str) << std::endl;
    }
    return 0;
}
