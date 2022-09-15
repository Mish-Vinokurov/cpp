#include <iostream>
#include <vector>

void InsertSort(std::vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int j = i - 1;
        while (j >= 0 && v[j] > v[j + 1]) {
            std::swap(v[j], v[j + 1]);
            j--;
        }
    }
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
    InsertSort(v);
    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    return 0;
}
