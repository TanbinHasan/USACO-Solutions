/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: angry
      LANG: C++
      CREATED: 08.10.2021 02:01:41
*/
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> ar(n), store;
  for (auto &i : ar) {
    cin >> i;
  }
  sort(ar.begin(), ar.end());
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    int rad = 1, cur = i, pos = i, dis = 1;
    for (int j = i + 1; j < n; ++j) {
      if (ar[j] - ar[cur] <= rad) {
        pos = j;
      } else {
        if (pos == i) break;
        cur = pos;
        if (ar[j] - ar[cur] <= (++rad)) {
          pos = j;
        } else {
          break;
        }
      }
    }
    dis += pos - i;
    rad = 1, cur = i, pos = i;
    for (int j = i - 1; j >= 0; --j) {
      if (ar[cur] - ar[j] <= rad) {
        pos = j;
      } else {
        if (pos == i) break;
        cur = pos;
        if (ar[cur] - ar[j] <= (++rad)) {
          pos = j;
        } else {
          break;
        }
      }
    }
    dis += i - pos;
    ans = max(ans, dis);
  }
  cout << ans;
  return 0;
}