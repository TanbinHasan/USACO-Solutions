/**
 *    author:  Tanbin_Hasan
 *    created: 10.11.2021 18:26:34
**/
#include <bits/stdc++.h>

using namespace std;

void Run_Case(void) {
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  int ans = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int sum = accumulate(ar.begin() + i, ar.begin() + j + 1, 0);
      int tot = j - i + 1;
      if (sum % tot) continue;
      int avg = sum / tot;
      for (int k = i; k <= j; ++k) {
        if (ar[k] == avg) {
          ++ans;
          break;
        }
      }
    }
  }
  cout << ans;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int total_test = 1, test_case = 0;
  // cin >> total_test; // Watch Carefully
  while (++test_case <= total_test) {
    Run_Case();
  }
  return 0;
}