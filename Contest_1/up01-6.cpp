#include <iostream>
#include <iomanip>


const static double eps = 0.0001;


struct Dot{
    double x, y;
    Dot(double x, double y) : x(x), y(y) {}
};

struct Line {
    double a, b, c;
    Line(Dot first, Dot second) {
        a = (second.y - first.y);
        b = -(second.x - first.x);
        c = -(second.y - first.y) * first.x + (second.x - first.x) * first.y;
    }
};


void get_cross(Line first, Line second) {
    double det = first.a * second.b - second.a * first.b;
    if(std::abs(det) < eps) {
        if(std::abs(first.a * second.c - first.c * second.a) < eps && std::abs(first.b * second.c - first.c * second.b) < eps) {
            std::cout << 2 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    } else {
        double x, y;
        x = - (first.c * second.b - second.c * first.b) / det;
        y = -(first.a * second.c - second.a * first.c) / det;
        std::cout << 1 << " " << std::fixed << std::setprecision (5) << x << " " << y << std::endl;
    }
}



int main () {
    double x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    get_cross (Line (Dot(x1, y1), Dot(x2, y2)), Line (Dot(x3, y3), Dot(x4, y4)));
}