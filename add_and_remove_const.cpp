#include <iostream>
#include <type_traits>

template<typename T>
struct AddConst {
  using type = const T;
};

template<typename T>
struct AddConst<const T> {
  using type = const T;
};

template<typename T>
struct RemoveConst {
  using type = T;
};

template<typename T>
struct RemoveConst<const T> {
  using type = T;
};

int main() {
  std::cout << is_same_v<AddConst<int>::type, const int> << "/n";
  std::cout << is_same_v<AddConst<const int>::type, const int> << "/n";
  std::cout << "/n";
  std::cout << is_same_v<RemoveConst<int>::type, const int> << "/n";
  std::cout << is_same_v<RemoveConst<const int>::type, const int> << "/n";
}
