/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: swap
      LANG: C++
      CREATED: 09.09.2021 18:28:38
*/
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<vector<int>> store(1);
  for (int i = 1; i <= n; ++i) {
    store[0].push_back(i);
  }
  vector<int> v = store.back();
  auto bg1 = next((v).begin(), a - 1);
  auto bg2 = next((v).begin(), c - 1);
  auto en1 = next((v).begin(), b);
  auto en2 = next((v).begin(), d);
  while (1) {
    reverse(bg1, en1);
    reverse(bg2, en2);
    if (v == store[0]) break;
    store.push_back(v);
  }
  int len = (int)store.size();
  k %= len;
  for (auto &i : store[k]) {
    cout << i << '\n';
  }
  return 0;
}