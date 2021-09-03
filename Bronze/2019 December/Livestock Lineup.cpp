/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: lineup
      LANG: C++
      CREATED: 04.09.2021 00:02:56
*/
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);
  vector<string> vs = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
  sort(vs.begin(), vs.end());
  set<pair<string,string>> sp;
  int n;
  cin >> n;
  while (n--) {
    string a, b, t;
    cin >> a >> t >> t >> t >> t >> b;
    sp.insert({a, b});
  }
  do {
    bool ok = true;
    for (auto &[x, y] : sp) {
      bool found = false;
      for (int i = 1; i < 8; ++i) {
        if ((vs[i - 1] == x && vs[i] == y) || (vs[i - 1] == y && vs[i] == x)) {
          found = true;
          break;
        }
      }
      ok = found;
      if (!ok) break;
    }
    if (ok) {
      for (auto &i : vs) {
        cout << i << '\n';
      }
      return 0;
    }
  } while (next_permutation(vs.begin(), vs.end())) ;
  return 0;
}