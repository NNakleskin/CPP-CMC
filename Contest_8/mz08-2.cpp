/* Функция вычисляет сумму a и b, если k равно 0. Если b равно 1, то функция возвращает a.
 В остальных случаях функция вызывает саму себя с параметрами a, функцией от (a, b-1, k) и k-1.*/


#include <iostream>

class Result {
public:
    Result (long long value, bool is_exception): value_ (value), is_exception_ (is_exception) {}
    long long GetValue () const { return value_; }
    bool IsException () const { return is_exception_; }
private:
    long long value_;
    bool is_exception_;
};

Result func (long long a, long long b, int k) {
    if (k == 0) {
        return Result (a + b, false);
    }
    if (b == 1) {
        return Result (a, false);
    }
    Result res = func (a, b - 1, k);
    if (res.IsException ()) {
        return res;
    }
    try {
        return func (a, res.GetValue (), k - 1);
    }
    catch (const Result& res) {
        return Result (res.GetValue (), true);
    }
}

int main () {
    long long a, b;
    int k;
    while (std::cin >> a >> b >> k) {
        Result res = func (a, b, k);
        std::cout << res.GetValue () << std::endl;
    }
    return 0;
}