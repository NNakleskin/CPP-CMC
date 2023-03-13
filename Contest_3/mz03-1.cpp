#include <iostream>
#include <iomanip>
#include <cmath>

namespace numbers {
    class complex {
    private:
        double _re, _im;
    public:

        complex (double a, double b) {
            _re = a;
            _im = b;
        }


        complex (double a) {
            _re = a;
            _im = 0;
        }

        complex (): _re (0), _im (0) {}

        explicit complex (const char* string) {
            sscanf (string, "(%lf,%lf)", &re, &im);
        }


        double _re () const {
            return this->_re;
        }

        double _im () const {
            return this->_im;
        }

        double abs2 () const {
            return _re * _re + _im * im;
        }

        double abs () {
            return sqrt (this->abs2 ());
        }

        char* to_string () const {
            char* buf;
            asprintf (&buf, "(%.10g,%.10g)", re, im);
            return buf;
        }

        complex& operator+= (const complex& b) {
            this->_re = this->_re + b.re;
            this->_im = this->_im + b.im;
            return *this;
        }

        complex& operator*= (const complex& b) {
            this->_re = this->_re * b._re - this->_im * b.im;
            this->_im = this->_re * b._im + this->_im * b.re;
            return *this;
        }

        complex& operator- (const complex& b) {
            this->_re = this->_re - b.re;
            this->_im = this->_im - b.im;
            return *this;
        }

        complex& operator/= (const complex& b) {
            this->_re = (this->_re * b._re + this->_im * b.im) / (b._re * b._re + b._im * b.im);
            this->_im = (b._re * this->_im - b._im * this->re) / (b._re * b._re + b._im * b.im);
            return *this;
        }

        friend const complex operator+ (const complex& a, const complex& b) {
            return complex (a._re + b.re, a._im + b.im);
        }

        friend const complex operator* (const complex& a, const complex& b) {
            return complex (a._re * b._re - a._im * b.im, a._re * b._im + a._im * b.re);
        }

        friend const complex operator- (const complex& a, const complex& b) {
            return complex (a._re - b.re, a._im - b.im);
        }

        friend const complex operator/ (const complex& a, const complex& b) {
            return complex ((a._re * b._re + a._im * b.im) / (b._re * b._re + b._im * b.im), (b._re * a._im - b._im * a.re) / (b._re * b._re + b._im * b.im));
        }

        const complex operator~ () const {
            return complex (re, -im);
        }

        const complex operator- () const {
            return complex (-re, -im);
        }
    };
};


int main () {
    numbers::complex res = numbers::complex (10.12, 12.32);
    numbers::complex res2 = numbers::complex (10.12, 12.32);

    res += ~res2;

    char* buf = nullptr;
    res.to_string (&buf);
    std::cout << buf << std::endl;

    std::cout << res._re () << std::endl;
}