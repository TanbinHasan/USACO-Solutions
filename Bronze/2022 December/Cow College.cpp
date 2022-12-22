#include <bits/stdc++.h>

#define int long long

using namespace std;

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  sort(ar.begin(), ar.end());
  int mx = 0;
  int x = 0;
  for (int i = 1; i <= 1000006; ++i) {
    int ind = lower_bound(ar.begin(), ar.end(), i) - (ar).begin();
    if (ind == (int)ar.size()) continue;
    int c = (int)ar.size() - ind;
    if (i * c > mx) mx = i * c, x = i;
  }
  cout << mx << " " << x << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}