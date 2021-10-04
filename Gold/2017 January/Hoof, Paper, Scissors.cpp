/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: hps
      LANG: C++
      CREATED: 04.10.2021 19:00:13
*/
#include <bits/stdc++.h>

using namespace std;

int val[100001][21][4];
vector<int> ar(100001);
int has[4][4];

int MxWin(int n, int pos, int k, int cur) {
  if (k < 0) return INT_MIN;
  if (pos == n) return 0;
  if (val[pos][k][cur] != -1) return val[pos][k][cur];
  int opt1 = MxWin(n, pos + 1, k - (cur && cur != 1), 1) + has[1][ar[pos]];
  int opt2 = MxWin(n, pos + 1, k - (cur && cur != 2), 2) + has[2][ar[pos]];
  int opt3 = MxWin(n, pos + 1, k - (cur && cur != 3), 3) + has[3][ar[pos]];
  return val[pos][k][cur] = max({0, opt1, opt2, opt3});
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    if (ch == 'H') ar[i] = 1;
    if (ch == 'P') ar[i] = 2;
    if (ch == 'S') ar[i] = 3;
  }
  has[1][3] = has[3][2] = has[2][1] = 1;
  memset(val, -1, sizeof val);
  cout << MxWin(n, 0, k, 0);
  return 0;
}