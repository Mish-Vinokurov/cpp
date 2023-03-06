#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <list>
#include <forward_list>

using namespace std;


template <class itr, typename T>
int Bs(itr l, itr r, int key, T arr) {
  l = arr.begin();
  r = arr.end();
  auto pivot = (l + (r - l) / 2);
  while (1 < r - l) {
    pivot = (l + (r - l) / 2);
    if (*pivot >= key) {
      r = pivot;
    } else {
      l = pivot;
    }
    if (*pivot == key) {
      return pivot - arr.begin();
    }
  }
  return -1;
}


template <class itr, typename T>
int BsBid(itr l, itr r, int key, T arrayy) {
  auto pivot = arrayy.begin();
  int dist = arrayy.size();
  while (dist > 0) {
    int i = 0;
    auto pivot = l;
    for (i = 0; i < dist / 2; ++i) {
      pivot++;
    }
    if (*pivot < key) {
      for (i = 0; i < dist / 2; ++i) {
        ++l;
      }
      dist -= i;
    } else {
      for (i = 0; i < dist / 2; ++i) {
        r--;
      }
      dist -= i;
    }
    if (*pivot == key) {
      auto fin = arrayy.begin();
      int i = 0;
      while (*fin != *pivot) {
        ++fin;
        i++;
      }
      return i;
    }
    if (dist == 1 && *l != key && *r != key) {
      return -1;
    }
  }
  return -1;
}


int main() {
  vector<int> v = {1, 2, 3, 4, 6, 7, 8, 9};
  list<int> l = {1, 2, 3, 4, 6, 7, 8, 9};
  
  cout << "RA tests here:" << '\n';
  cout <<Bs(v.begin(), v.end(), 3, v) << '\n';
  cout << Bs(v.begin(), v.end(), 5, v) << '\n';

  cout << "Bid tests here:"<< '\n';
  cout <<BsBid(l.begin(), l.end(), 3, l) << '\n';
  cout <<BsBid(l.begin(), l.end(), 5, l) << '\n';
}
