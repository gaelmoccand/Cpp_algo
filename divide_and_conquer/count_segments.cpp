#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> res(points.size());
  //write your code here

  std::sort(starts.begin(), starts.end());
  std::sort(ends.begin(), ends.end());
  for (const auto& point:points) {
    auto start = std::upper_bound(starts.begin(),starts.end(), point);
    auto end = std::lower_bound(ends.begin(),starts.end(), point);

    auto cnt = 0;
    if (start != starts.end()) {
      cnt += std::distance(start, starts.end());
    }
    if (end != ends.end()) {
      cnt += std::distance(ends.begin(), end);
    } 
    if ((start == starts.end()) && (end == ends.end())) {
      cnt = 0;
    }
    res.emplace_back(cnt);

  }

  return res;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
