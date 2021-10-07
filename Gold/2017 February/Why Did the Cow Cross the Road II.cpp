/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: nocross
      LANG: C++
      CREATED: 07.10.2021 18:31:45
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> val(1001, vector<int>(1001, -1));
vector<int> a(1001), b(1001);

int MxCrossWalk(int n, int m) {
  if (n < 0 || m < 0) return 0;
  if (val[n][m] != -1) return val[n][m];
  int ok = (abs(a[n] - b[m]) <= 4);
  if (ok) return val[n][m] = MxCrossWalk(n - 1, m - 1) + ok;
  return val[n][m] = max(MxCrossWalk(n - 1, m), MxCrossWalk(n, m - 1));
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("nocross.in", "r", stdin);
  freopen("nocross.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  cout << MxCrossWalk(n - 1, n - 1);
  return 0;
}