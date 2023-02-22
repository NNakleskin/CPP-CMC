#include <iostream>
#include <iomanip>


class dot {
public:
    double x, y;
    dot (double a, double b) {
        x = a;
        y = b;
    }
};


class line {
public:
    dot first;
    dot second;
    line (double a, double b, double c, double d): first (a, b), second (c, d) {}
};


void get_cross (line a, line b) {
    double n = 0;
    if (abs ((-a.first.x) / (a.second.x - a.first.x) - (-a.first.y) / (a.second.y - a.first.y) -
        (-b.first.x) / (b.second.x - b.first.x) + (-b.first.y) / (b.second.y - b.first.y)) < 0.01 &&
        abs (((5 - a.first.x) / (a.second.x - a.first.x) - (5 - a.first.y) / (a.second.y - a.first.y)) -
            (5 - b.first.x) / (b.second.x - b.first.x) + (5 - b.first.y) / (b.second.y - b.first.y)) < 0.01) {
        std::cout << 2 << std::endl;
        return;
    }
    if (a.second.y - a.first.y != 0) {
        double q = (a.second.x - a.first.x) / (a.first.y - a.second.y);
        double sn = (b.first.x - b.second.x) + (b.first.y - b.second.y) * q;
        if (!sn) {
            std::cout << 0 << std::endl;
            return;
        }
        double fn = (b.first.x - a.first.x) + (b.first.y - a.first.y) * q;
        n = fn / sn;
    } else {
        if (!(b.first.y - b.second.y)) {
            std::cout << 0 << std::endl;
            return;
        }
        n = (b.first.y - a.first.y) / (b.first.y - b.second.y);
    }
    std::cout << 1 << std::endl;
    std::cout << std::setprecision (6) << b.first.x + (b.second.x - b.first.x) * n << std::endl;
    std::cout << std::setprecision (6) << b.first.y + (b.second.y - b.first.y) * n << std::endl;
}


int main () {
    double x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    get_cross (line (x1, y1, x2, y2), line (x3, y3, x4, y4));
}
/*
0
0
0
5
0
0
0
10

0

Bad test
*/