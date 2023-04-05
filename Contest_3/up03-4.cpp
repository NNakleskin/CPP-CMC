#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"


int main (int argc, char** argv) {
    const numbers::complex C (argv[1]);
    const double R = strtod (argv[2], nullptr);
    const int N = (int) strtol (argv[3], nullptr, 10);
    std::vector<std::string> arr;
    for (int i = 4; i < argc; ++i) {
        arr.emplace_back (argv[i]);
    }
    numbers::complex res = 0;
    const double a = 2 * M_PI / N;
    for (double i = 0; i < N; ++i) {
        double r = a * (i + 0.5);
        double r2 = a * i;
        double r3 = a * (i + 1);
        numbers::complex z = C + numbers::complex (R * cos (r), R * sin (r));
        res += numbers::eval (arr, z) * R * numbers::complex (cos (r3) - cos (r2), sin (r3) - sin (r2));
    }
    std::cout << res.to_string () << std::endl;
}