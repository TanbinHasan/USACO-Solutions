/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: circlecross
      LANG: C++
      CREATED: 05.07.2021 20:35:58
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("circlecross.in" , "r" , stdin) ;
  freopen("circlecross.out" , "w" , stdout) ;
  vector<vector<int>> cnt(26) ;
  string s ;
  cin >> s ;
  for (int i = 0 ; i < 52 ; ++i) {
    cnt[s[i] - 'A'].push_back(i) ;
  }
  int ans = 0 ;
  for (int i = 0 ; i < 26 ; ++i) {
    int as = cnt[i][0] , ae = cnt[i][1] ;
    for (int j = i + 1 ; j < 26 ; ++j) {
      int bs = cnt[j][0] , be = cnt[j][1] ;
      if ((ae > bs && bs > as && be > ae) || (be > as && as > bs && ae > be)) {
        ++ans ;
      }
    }
  }
  cout << ans ;
  return 0 ;
}