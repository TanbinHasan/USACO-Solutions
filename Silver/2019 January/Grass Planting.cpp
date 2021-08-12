/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: planting
      LANG: C++
      CREATED: 13.08.2021 00:43:11
*/
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> cnt(n);
  while (--n) {
    int x, y;
    cin >> x >> y;
    ++cnt[x], ++cnt[y];
  }
  cout << 1 + *max_element(cnt.begin(), cnt.end());
  return 0;
}