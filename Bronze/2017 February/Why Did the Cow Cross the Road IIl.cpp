/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: cowqueue
      LANG: C++
      CREATED: 04.09.2021 17:21:34
*/
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);
  int n;
  cin >> n;
  vector<pair<int64_t,int64_t>> vp(n);
  for (auto &[x, y] : vp) {
    cin >> x >> y;
  }
  sort(vp.begin(), vp.end());
  int64_t mn = vp[0].first + vp[0].second;
  for (int i = 1; i < n; ++i) {
    if (mn >= vp[i].first) {
      mn += vp[i].second;
    } else {
      mn = vp[i].first + vp[i].second;
    }
  }
  cout << mn;
  return 0;
}