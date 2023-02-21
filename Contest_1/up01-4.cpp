#include <iostream>
#include <cmath>
#include <iomanip>


int main() {
    int n = 0;
    double sum = 0;
    double average = 0;
    double disp = 0;

    double num;
    double first_sum = 0;

    while(std::cin >> num) {
        n++;
        sum += num;
        first_sum += num * num;
    }
    average = sum / n;
    disp = (first_sum - 2 * average * sum + n * average * average) / n;
    std::cout << std::setprecision(11) << average << '\n';
    std::cout << std::setprecision(11) << sqrt(disp) << '\n';
}