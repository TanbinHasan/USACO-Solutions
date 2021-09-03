/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: factory
      LANG: C++
      CREATED: 03.09.2021 03:08:54
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(101);
bitset<101> vis;
vector<int> cnt(101);

void DFS(int node) {
  vis[node] = 1;
  ++cnt[node];
  for (auto &child : adj[node]) {
    if (vis[child]) continue;
    DFS(child);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  for (int i = 1; i <= n; ++i) {
    vis.reset();
    DFS(i);
  }
  int ans = -1;
  for (int64_t i = 1; i <= n; ++i) {
    if (cnt[i] == n) {
      ans = i;
      break;
    }
  }
  cout << ans;
  return 0;
}