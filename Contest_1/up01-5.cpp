#include <iostream>
#include <climits>


int main () {
    int offset;
    while (std::cin >> std::hex >> offset) {
        std::cout << std::cin.tellg() << '\n';
        unsigned int num = 0;
        unsigned int res = 0;
        int count = 0;
        while (std::cin >> std::hex >> num) {
            std::cout << num;
            //if (std::cin.tellg () != 2) { break; }
            res = num + (res << sizeof (unsigned int) * CHAR_BIT / 4);
            count++;
            if (count == 4) {
                break;
            }
        }
        std::cout << res << '\n';
        //if (std::cin.eof ()) { break; }
    }
}