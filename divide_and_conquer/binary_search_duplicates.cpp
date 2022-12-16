#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  auto left = a.end(), right = a.end(); 

  while (left < right) {
    if ( x < *left || x > *std::prev(right)) {

    }
    auto N = std::distance(left, right);
    auto pivot = std::next(left, N/2);
    if(x == *pivot) {
      while (*pivot == *std::prev(pivot)) // any duplicates
        pivot = std::prev(pivot);
      return std::distance(a.cbegin(), pivot);
    }
    else if (x < *pivot) {
      while (*pivot == *std::prev(pivot)) // any duplicates
        pivot = std::prev(pivot);
      right = pivot;
    } else {
      while (*pivot == *std::next(pivot)) // any duplicates
        pivot = std::next(pivot);
      left = pivot;
    }
  }

  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << linear_search(a, b[i]) << ' ';
  }
}
