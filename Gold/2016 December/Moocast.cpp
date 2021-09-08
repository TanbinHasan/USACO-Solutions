/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: moocast
      LANG: C++
      CREATED: 09.09.2021 02:15:06
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bitset<1000> vis;

void DFS(int node) {
  vis[node] = 1;
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
  vector<pair<int,int>> vp(n);
  for (auto &[x, y] : vp) {
    cin >> x >> y;
  }
  int low = 0, high = (int)1.25e9, mid;
  int ans = INT_MAX;
  while (low <= high) {
    mid = low + (high - low) / 2;
    adj.assign(n, {});
    vis.reset();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        int dx = vp[i].first - vp[j].first;
        int dy = vp[i].second - vp[j].second;
        int dis = dx * dx + dy * dy;
        if (dis <= mid) adj[i].push_back(j);
      }
    }
    DFS(0);
    auto valid = [&](int n) {
      for (int i = 0; i < n; ++i) {
        if (!vis[i]) return false;
      }
      return true;
    };
    if (valid(n)) {
      high = mid - 1;
      ans = min(ans, mid);
    } else {
      low = mid + 1;
    }
  }
  cout << ans;
  return 0;
}