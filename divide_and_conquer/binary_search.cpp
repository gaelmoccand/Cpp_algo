#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  auto first = a.begin(), last = a.end(); 

  while (first < last) {
    if ( x < *first || x > *std::prev(last)) {
      return -1;
    }
    const auto N = std::distance(first, last);
    const auto pivot = std::next(first, N/2);
    if (x == *pivot) {
      return std::distance(a.begin(), pivot);
    } else if (x < *pivot) {
      last =  pivot;
    } else {
      first = pivot;
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
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
