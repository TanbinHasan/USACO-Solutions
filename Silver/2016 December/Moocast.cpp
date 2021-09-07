/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: moocast
      LANG: C++
      CREATED: 06.09.2021 00:00:41
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(200);
bitset<200> vis;
set<int> s;

void DFS(int node) {
  vis[node] = 1;
  s.insert(node);
  for (auto &child : adj[node]) {
    if (vis[child]) continue;
    DFS(child);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  int n;
  cin >> n;
  vector<tuple<int64_t,int64_t,int64_t>> vt(n);
  for (auto &[x, y, z] : vt) {
    cin >> x >> y >> z;
  }
  for (int i = 0; i < n; ++i) {
    auto [a, b, c] = vt[i];
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      auto [x, y, z] = vt[j];
      int64_t dis = (a - x) * (a - x) + (b - y) * (b - y);
      if (c * c >= dis) adj[i].push_back(j);
    }
  }
  int mx = 1;
  for (int i = 0; i < n; ++i) {
    vis.reset();
    s.clear();
    DFS(i);
    mx = max(mx, (int)s.size());
  }
  cout << mx;
  return 0;
}