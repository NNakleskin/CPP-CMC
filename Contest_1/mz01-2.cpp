#include <iostream>


class A {
    bool type;
    int num;
public:
    A(A const &a) {
        std::cin >> num;
        num += a.num;
        type = true;
    }
    A() {
        std::cin >> num;
        type = false;
    }

    ~A() {
        if(type) {
            std::cout << num << std::endl;
        } else {
        }
    }
    
};

/*
int main()
{
    A a, b(a);
} */
