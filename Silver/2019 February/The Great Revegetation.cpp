/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: revegetate
      LANG: C++
      CREATED: 11.09.2021 15:39:27
*/
#include <bits/stdc++.h>

using namespace std;

set<pair<int,int>> same;
vector<vector<int>> adj(100001);
bitset<100001> vis, color;
bool good = true;

void DFS(int node, int col) {
  vis[node] = 1;
  color[node] = col;
  for (auto &child : adj[node]) {
    if (vis[child]) {
      if (color[child] == color[node] && !same.count({child, node})) {
        good = false;
        return;
      }
      continue;
    }
    if (same.count({child, node})) DFS(child, col);
    else DFS(child, !col);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  while (m--) {
    char ch;
    int x, y;
    cin >> ch >> x >> y;
    if (ch == 'S') same.insert({x, y}), same.insert({y, x});
    adj[x].push_back(y), adj[y].push_back(x);
  }
  int64_t zeroes = 0;
  for (int i = 1; i <= n && good; ++i) {
    if (!vis[i]) {
      DFS(i, 0);
      ++zeroes;
    }
  }
  if (!good) {
    cout << 0;
    return 0;
  }
  cout << 1 << string(zeroes, '0');
  return 0;
}