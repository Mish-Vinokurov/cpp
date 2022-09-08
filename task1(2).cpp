#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    double x1, x2;
    if (d < 0 || (b == 0 && a == 0)) {
        std::cout << "NOSOLV";
        return 0;
    }
    if (a == 0 && b != 0) {
        std::cout << c / - b;
        return 0;
    }
    if (d == 0) {
        std::cout << - b / 2 / a;
        return 0;
    }
    x1 = (- b + sqrt(d)) / 2 / a;
    x2 = (- b - sqrt(d)) / 2 / a;
    std::cout << x1 << " " << x2;
    return 0;
}
