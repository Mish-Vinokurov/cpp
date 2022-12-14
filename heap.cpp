#include <iostream>
#include <vector>
#include <algorithm>

size_t Parent(size_t i) {
  return (i - 1) / 2;
}

size_t LeftChild(size_t i) {
  return 2 * i + 1;
}

size_t RightChild(size_t i) {
  return 2 * i + 2;
}

template <class T>
class Heap {
 private:
  std::vector<T> arr_;

 public:
  Heap() = default;
  Heap(const std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size();i++) {
      Insert(arr[i]);
    }
  }
  void Insert(const T& elem) {
    arr_.push_back(elem);
    SiftUp(arr_.size() - 1);
  }
  void SiftDown(size_t i) {
    size_t left = LeftChild(i);
    size_t right = RightChild(i);
    size_t largest = i;
    if (left < arr_.size() && arr_[left] > arr_[largest]) {
      largest = left;
    }
    if (right < arr_.size() && arr_[right] > arr_[largest]) {
      largest = right;
    }
    if (largest != i) {
      std::swap(arr_[i], arr_[largest]);
      SiftDown(largest);
    }
  }
  void SiftUp(size_t i) {
    size_t parent = Parent(i);
    if (i >= 1 && arr_[parent] < arr_[i]) {
      std::swap(arr_[i], arr_[parent]);
      SiftUp(parent);
    }
  }
  void Delete(size_t i) {
    std::swap(arr_[i], arr_[arr_.size() - 1]);
    arr_.pop_back();
    SiftDown(i);
  }
  void Print() const {
    size_t k = 1;
    for (size_t i = 1; i <= arr_.size(); i++) {
      std::cout << arr_[i - 1] << " ";
      if (i == k) {
        std::cout << "\n";
        k *= 2;
        k++;
      }
    }
    std::cout << "\n" << "\n";
  }
  T Max() const {
    return arr_[0];
  }
};

int main() {
  int n, a;
  std::cin >> n;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    v.push_back(a);
  }
  Heap heap(v);
  //heap.Print();
  //heap.Delete(0);
  //heap.Print();
  //heap.Delete(0);
  //heap.Print();
  std::cout << heap.Max() << " ";
  return 0;
}
