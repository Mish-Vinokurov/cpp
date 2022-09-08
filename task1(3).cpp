#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    x += y;
    y -= x;
    x += y;
    std::cout << x << " " << - y;
    return 0;
}