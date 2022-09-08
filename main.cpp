#include <iostream>

int main() {
    std::cout << "Choose E (energy) or F (force) or q (electric potential)";
    char l;
    std::cin >> l;
    if (l == 'E') {
        std::cout << "Put your energy in joules ";
        double E;
        std::cin >> E;
        E = E * 10000000;
        std::cout << "Your energy in ergs: " << E;
    }
    if (l == 'F') {
        std::cout << "Put your force in newtons ";
        double F;
        std::cin >> F;
        F = F * 100000;
        std::cout << "Your force in deans: " << F;
    }
    if (l == 'q') {
        std::cout << "Put your electric potential in volts ";
        double q;
        std::cin >> q;
        q = q * 0.00334;
        std::cout << "Your electric potential in GHS Units: " << q;
    }

}