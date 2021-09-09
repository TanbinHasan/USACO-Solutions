/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: revegetate
      LANG: C++
      CREATED: 09.09.2021 14:56:26
*/
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> col(n + 1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y), adj[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    set<int> has = {1, 2, 3, 4};
    for (auto &child : adj[i]) {
      if (col[child]) has.erase(col[child]);
    }
    col[i] = *(has).begin();
    cout << col[i];
  }
  return 0;
}