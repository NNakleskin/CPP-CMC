#include <iostream>


int main () {
    char cur, prev;
    int count = 1;
    bool indicate = false;
    if (!(std::cin.get (prev))) { return 0; }
    if (!(std::cin.get (cur))) {
        if (prev == '#') {
            std::cout << "##1#";
        } else {
            std::cout << prev;
        }
        return 0;
    }
    while (1) {
        if (prev == cur) {
            count++;
        } else if ((cur != prev && count <= 4) && prev != '#') {
            for (int i = 0; i < count; i++) {
                std::cout << prev;
            }
            count = 1;
        } else if ((cur != prev && count > 4) || prev == '#') {
            std::cout << '#' << prev << std::hex << count << '#';
            count = 1;
        }
        prev = cur;
        if (indicate) {
            break;
        }
        if (!(std::cin.get (cur))) {
            cur++;
            indicate = true;
        }
    }
}