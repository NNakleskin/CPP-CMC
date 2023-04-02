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