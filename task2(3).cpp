#include <iostream>
#include <vector>

bool BinSearch(std::vector<int>& v, int x) {
    int left = 0, right = v.size() - 1;
    while (left < right) {
        int i = left + (right - left) / 2;
        if (v[i] == x) {
            return true;
        }
        if (v[i] < x) {
            left = i;
        } else {
            right = i;
        }
    }
    return v[left] == x;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    int x;
    std::cin >> x;
    if (BinSearch(v, x)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}



