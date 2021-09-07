/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: fenceplan
      LANG: C++
      CREATED: 08.09.2021 00:13:40
*/
#include <bits/stdc++.h>

using namespace std;

pair<int,int> x, y;
vector<pair<int,int>> vp(1);
vector<vector<int>> adj(100001);
bitset<100001> vis;

void DFS(int node) {
  vis[node] = 1;
  x.first = min(x.first, vp[node].first);
  x.second = max(x.second, vp[node].first);
  y.first = min(y.first, vp[node].second);
  y.second = max(y.second, vp[node].second);
  for (auto &child : adj[node]) {
    if (vis[child]) continue;
    DFS(child);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    vp.push_back({a, b});
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b), adj[b].push_back(a);
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      x = y = {INT_MAX, INT_MIN};
      DFS(i);
      ans = min(ans, 2 * ((x.second - x.first) + (y.second - y.first)));
    }
  }
  cout << ans;
  return 0;
}