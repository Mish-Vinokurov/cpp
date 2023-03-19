#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>
#include <random>

int main() {
    const int N = 1000000; 
    std::vector<int> v(N); 
    std::array<int, N> a; 
    std::set<int> s; 

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, N);

    for (int i = 0; i < N; ++i) {
        int x = dis(gen);
        v[i] = x;
        a[i] = x;
        s.insert(x);
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    std::sort(v.begin(), v.end());
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    std::sort(a.begin(), a.end());
    auto end2 = std::chrono::high_resolution_clock::now();

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        s.insert(dis(gen));
    }
    auto end3 = std::chrono::high_resolution_clock::now();

    int t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();
    int t2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();
    int t3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count(); 

    std::cout << "std::vector: " << t1 << " ms" << std::endl;
    std::cout << "std::array: " << t2 << " ms" << std::endl;
    std::cout << "std::set: " << t3 << " ms" << std::endl;

    return 0;
} 

