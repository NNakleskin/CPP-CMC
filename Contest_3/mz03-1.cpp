/*
В пространстве имен numbers реализуйте класс complex для комплексных чисел над типом double. Класс должен определять:

Конструкторы по умолчанию, от одного и двух аргументов. Должен реализовываться одним конструктором.
Явный (explicit) конструктор из типа std::string, который преобразовывает строку в значение complex. Строка имеет формат (RE,IM), то есть вещественная и мнимая части (числа типа double) записываются через запятую в круглых скобках. Например, строка "(1.0,-5)" определяет комплексное число (1.0,-5.0). Проверка на ошибки не требуется.
Методы re и im для получения вещественной и мнимой части числа.
Метод abs2 для получения квадрата модуля числа.
Метод abs для получения модуля числа.
Метод to_string, который преобразовывает комплексное число в строковое представление (см. выше) и возвращает объект типа std::string. Вещественные числа выводятся с 10 значащими цифрами в формате %.10g.
Операции +=, -=, *=, /=.
Операции сложения, вычитания, умножения и деления в обычной инфиксной форме, которые должны быть определены через соответствующие операции присваивания.
Префиксную операцию ~, которая возвращает новое число, комплексно-сопряженное к аргументу.
Префиксную операцию - смены знака.
*/


#include <string>
#include <cmath>

namespace numbers {
    class complex {
    public:
        complex (double a, double b) {
            re_ = a;
            im_ = b;
        }


        complex (double a) {
            re_ = a;
            im_ = 0;
        }

        complex (): re_ (0), im_ (0) {}

        explicit complex (const char* string) {
            sscanf (string, "(%lf,%lf)", &re_, &im_);
        }

        double re () const { return re_; }
        double im () const { return im_; }
        double abs2 () const { return re_ * re_ + im_ * im_; }
        double abs () const { return sqrt (abs2 ()); }

        char* to_string () const {
            char* buf;
            asprintf (&buf, "(%.10g,%.10g)", re_, im_);
            return buf;
        }

        complex& operator+=(const complex& other) {
            re_ += other.re_;
            im_ += other.im_;
            return *this;
        }

        complex& operator-=(const complex& other) {
            re_ -= other.re_;
            im_ -= other.im_;
            return *this;
        }

        complex& operator*=(const complex& other) {
            double re = re_ * other.re_ - im_ * other.im_;
            double im = re_ * other.im_ + im_ * other.re_;
            re_ = re;
            im_ = im;
            return *this;
        }

        complex& operator/=(const complex& other) {
            double denom = other.re_ * other.re_ + other.im_ * other.im_;
            double re = (re_ * other.re_ + im_ * other.im_) / denom;
            double im = (im_ * other.re_ - re_ * other.im_) / denom;
            re_ = re;
            im_ = im;
            return *this;
        }

        friend complex operator+(const complex& x, const complex& y) { return complex (x) += y; }
        friend complex operator-(const complex& x, const complex& y) { return complex (x) -= y; }
        friend complex operator*(const complex& x, const complex& y) { return complex (x) *= y; }
        friend complex operator/(const complex& x, const complex& y) { return complex (x) /= y; }

        complex operator~() const { return complex (re_, -im_); }

        friend complex operator-(const complex& x) { return complex (-x.re_, -x.im_); }

    private:
        double re_, im_;
    };
}
