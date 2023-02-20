#include <iostream>


class Sum {
    int sum;
public:
    Sum(int a, int b) : sum(a + b) {} // constructor
    Sum(Sum a, int b) : sum(a.sum + b) {}
    Sum(int a, Sum b) : sum(a + b.sum) {}

    int get() const {
        return sum;
    }

};

/*
int main() {

    Sum(Sum(1, 2), 3);
} */
