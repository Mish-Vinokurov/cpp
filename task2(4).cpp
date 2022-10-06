#include <iostream>
#include <vector>

int max(int a, int b) {
    return (a > b ? a : b );
}

int answer(std::vector <int>& a, int n, std::vector <int>& b, int m) {
    std::vector <int> layer_first(m + 1);
    for (int i = 0; i <= m; ++i) {
        layer_first[i] = 0;
    }
    std::vector <int> layer_second(m + 1);
    layer_second[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                layer_second[j] = layer_first[j - 1] + 1;
            } else {
                layer_second[j] = max(layer_first[j], layer_second[j - 1]);
            }
        }
        for (int k = 0; k <= m; ++k) {
            layer_first[k] = layer_second[k];
        }
    }
    return layer_second[m];
}

int main() {
    int n;
    std::cout << "Enter the length of thr first sequence";
    std::cin >> n;
    std::cout << "Enter the first sequence";
    std::vector <int> sequence_first(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence_first[i];
    }
    int m;
    std::cout << "Enter the length of thr second sequence";
    std::cin >> m;
    std::cout << "Enter the second sequence";
    std::vector <int> sequence_second(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> sequence_second[i];
    }
    std::cout << "The length of the common sequence: " << answer(sequence_first, n, sequence_second, m);
}