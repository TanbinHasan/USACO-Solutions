/*
  ID: Tanbin Hasan Ador [tanvirh5]
  TASK: closing
  LANG: C++
*/
#include <bits/stdc++.h>

#define int long long

using namespace std;

class DSU {
 public:
  vector<int> par, size;
  DSU(int n) {
    for (int i = 0; i < n; ++i) par.push_back(i);
    size = vector<int>(n, 1);
  }
  int get(int x) {
    while (par[x] != x) x = par[x];
    return x;
  }
  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (size[x] < size[y]) swap(x, y);
    if (x == y) return false;
    size[x] += size[y];
    par[y] = x;
    return true;
  }
};

#define FileIO                  
// #define MultipleCase         
void Solve(__attribute__((unused)) int tc) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
    --i;
  }
  reverse(ar.begin(), ar.end());
  vector<string> ans;
  vector<bool> vis(n);
  DSU dsu(n);
  int comp = 0;
  for (auto &i : ar) {
    vis[i] = true;
    ++comp;
    for (auto &j : adj[i]) {
      if (!vis[j]) continue;
      if (!dsu.unite(i, j)) continue;
      --comp;
    }
    if (comp == 1) ans.push_back("YES");
    else ans.push_back("NO");
  }
  reverse(ans.begin(), ans.end());
  for (auto &i : ans) {
    cout << i << '\n';
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef FileIO
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);
#endif
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}