#include <iostream>
#include <string>

class ReversePrinter {
public:
    std::string str;
    ReversePrinter () {
        if (!(std::cin >> str)) {
            throw 0;
        }
        try {
            ReversePrinter next_lol;
        }
        catch (...) {
        }
    }
    ~ReversePrinter () {
        std::cout << str << std::endl;
    }
};

int main () {
    try {
        ReversePrinter lol;
    }
    catch (...) {
    }

    return 0;
}