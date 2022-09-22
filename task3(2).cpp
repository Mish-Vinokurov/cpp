#include <iostream>
#include <vector>

void Merge(std::vector<int>& Array, int first, int last) {
    int middle = first + (last - first) / 2;
    int start = first, final = middle + 1;
    std::vector<int> mas(last - first + 2);
    for (int j = first; j <= last; j++) {
        if (start <= middle && (final > last || Array[start] < Array[final])) {
            mas[j] = Array[start];
            start++;
        } else {
            mas[j] = Array[final];
            final++;
        }
    }
    for (int j = first; j <= last; j++) {
        Array[j] = mas[j];
    }
}
void MergeSort(std::vector<int>& Array, int first, int last) {
    if (first < last) {
        MergeSort(Array, first, (first + last) / 2);
        MergeSort(Array, (first + last) / 2 + 1, last);
        Merge(Array, first, last);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> Array;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        Array.push_back(a);
    }
    int first = 0;
    int last = n - 1;
    MergeSort(Array, first, last);
    for (int i = 0; i < n; i++) {
        std::cout << Array[i] << " ";
    }
    return 0;
}