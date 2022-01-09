/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: blist
      LANG: C++
      CREATED: 30.12.2021 02:06:11
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T,class C = less<T>> using iset = tree<T,null_type,C,rb_tree_tag,tree_order_statistics_node_update>;
template <class T,class C = less_equal<T>> using imultiset = tree<T,null_type,C,rb_tree_tag,tree_order_statistics_node_update>;

void Aufdecken(int TC) {
  int n;
  cin >> n;
  vector<tuple<int,int,int>> vt(n);
  for (auto &[x, y, z] : vt) {
    cin >> x >> y >> z;
  }
  sort(vt.begin(), vt.end(),[&](tuple<int,int,int> a, tuple<int,int,int> b) {
    if (get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
    return get<0>(a) < get<0>(b);
  });
  set<int> used;
  set<int> buck;
  vector<vector<int>> store(n);
  for (int i = 1; i <= 1001; ++i) buck.insert(i);
  int pre = -1;
  for (int i = 0; i < n; ++i) {
    auto [x, y, z] = vt[i];
    for (int j = i - 1; j >= 0; --j) {
      auto [a, b, c] = vt[j];
      if (x <= b) continue;
      while (!store[j].empty()) buck.insert(store[j].back()), store[j].pop_back();
    }
    for (int j = 0; j < z; ++j) {
      auto it = *(buck).begin();
      store[i].push_back(it);
      used.insert(it);
      buck.erase(it);
    }
  }
  cout << (int)used.size();
}

int main(void) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);
  int TT = 1, TC = 0;
  // cin >> TT;                         
  while (++TC <= TT) {
    Aufdecken(TC);
  }
  return 0;
}