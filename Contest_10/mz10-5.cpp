#include <iostream>
#include <stack>
#include <string>

int priority (char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

int main () {
    std::string str;
    std::getline (std::cin, str);
    std::stack<std::string> stack;
    for (char c : str) {
        if (c >= 'a' && c <= 'z') {
            stack.push (std::string (1, c));
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            std::string b = stack.top ();
            stack.pop ();
            std::string a = stack.top ();
            stack.pop ();
            std::string expr = "(" + a + c + b + ")";
            stack.push (expr);
        }
    }
    std::cout << stack.top () << std::endl;
    return 0;
}