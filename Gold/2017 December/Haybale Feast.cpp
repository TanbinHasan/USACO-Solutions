/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: hayfeast
      LANG: C++
      CREATED: 12.11.2021 20:17:19
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using iset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using imultiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

void Aufdecken(int TC) {
  int64_t n, m;
  cin >> n >> m;
  vector<pair<int,int>> ar(n);
  for (auto &[y, x] : ar) {
    cin >> x >> y;
  }
  int mn = INT_MAX, ind = 0;
  int64_t sum = 0;
  multiset<pair<int,int>,greater<pair<int,int>>> ms;
  for (auto &[x, y] : ar) {
    ms.insert({x, y});
    sum += y;
    if (sum < m) continue;
    int cur = (*(ms).begin()).first;
    mn = min(mn, cur);
    if (sum >= m) {
      auto [px, py] = ar[ind++];
      ms.erase(ms.find({px, py}));
      sum -= py;
    }
  }
  cout << mn;
}

int main(void) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("hayfeast.in", "r", stdin);
  freopen("hayfeast.out", "w", stdout);
  int TT = 1, TC = 0;
  // cin >> TT;                         
  while (++TC <= TT) {
    Aufdecken(TC);
  }
  return 0;
}