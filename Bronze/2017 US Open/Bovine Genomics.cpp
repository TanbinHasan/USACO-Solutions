/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: cownomics
      LANG: C++
      CREATED: 05.07.2021 17:41:50
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("cownomics.in" , "r" , stdin) ;
  freopen("cownomics.out" , "w" , stdout) ;
  int n , m ;
  cin >> n >> m ;
  vector<set<char>> spotty(m) ;
  vector<set<char>> plain(m) ;
  for (int i = 0 ; i < n ; ++i) {
    string s ;
    cin >> s ;
    for (int64_t j = 0 ; j < m ; ++j) {
      spotty[j].insert(s[j]) ;
    }
  }
  for (int i = 0 ; i < n ; ++i) {
    string s ;
    cin >> s ;
    for (int64_t j = 0 ; j < m ; ++j) {
      plain[j].insert(s[j]) ;
    }
  }
  int ans = 0 ;
  for (int i = 0 ; i < m ; ++i) {
    int ok = 1 ;
    for (auto &j : spotty[i]) {
      auto it = plain[i].find(j) ;
      if (it != plain[i].end()) {
        ok = 0 ;
        break ;
      }
    }
    ans += ok ;
  }
  cout << ans ;
  return 0 ;
}