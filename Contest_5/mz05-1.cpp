#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Number {
    public:
    int num;
    int bin_count;
    Number(int x){
        num  = x;
        bin_count = 0;
        int tmp = num;
        for (; tmp; bin_count++)
            tmp &= (tmp - 1);
    }
};

bool operator<(const Number& lhs, const Number& rhs) {
    return lhs.bin_count < rhs.bin_count;
}

int main () {
    std::vector<Number> vect;

    int num;

    while(std::cin >> num) {
        Number A(num);
        vect.push_back(A);
    }

    stable_sort (vect.begin (), vect.end ());

    for (const Number& e : vect){
        std::cout << e.num << std::endl;
    }
}