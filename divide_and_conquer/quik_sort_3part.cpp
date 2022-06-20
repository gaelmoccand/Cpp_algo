#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

std::pair<int,int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int m2 = l;
  int m1 = 1;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      m2++;
      swap(a[i], a[m2]);
    }
    else if (a[i] == x) {
      m1++;
      m2++;
      std::rotate(a.begin() + l, a.begin() + i, a.begin() + i + 1);
    }

  }

  std::rotate(a.begin() + l, a.begin() + m1 + l, a.begin() + m2 + 1);
  m1 = m2 -m1 + 1;
  return {m1, m2};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
 // swap(a[l], a[k]);
  auto m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
