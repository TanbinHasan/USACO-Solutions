/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: teamwork
      LANG: C++
      CREATED: 04.10.2021 16:01:02
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> store(10001);
vector<int> val(10001, -1);

int64_t MxSum(int n, int pos, int k) {
  if (pos == n) return 0;
  if (val[pos] != -1) return val[pos];
  int64_t best = 0;
  for (int i = 1; i <= k; ++i) {
    if (pos + i - 1 >= n) break;
    int64_t cal = MxSum(n, pos + i, k) + i * store[pos][i - 1];
    best = max(best, cal);
  }
  return val[pos] = best;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    int mx = 0;
    for (int j = i; j < min(n, i + k); ++j) {
      mx = max(mx, ar[j]);
      store[i].push_back(mx);
    }
  }
  cout << MxSum(n, 0, k);
  return 0;
}