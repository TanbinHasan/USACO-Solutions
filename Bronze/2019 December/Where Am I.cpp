/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: whereami
      LANG: C++
      CREATED: 06.07.2021 17:35:08
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("whereami.in" , "r" , stdin) ;
  freopen("whereami.out" , "w" , stdout) ;
  int64_t len ;
  cin >> len ;
  string s ;
  cin >> s ;
  map<string,int64_t> cnt ;
  for (int64_t l = 1 ; l < len + 1 ; ++l) {
    bool ok = true ;
    for (int64_t i = 0 ; i <= len - l ; ++i) {
      string sub = s.substr(i , l) ;
      if (cnt[sub]) {
        ok = false ;
        break ;
      }
      ++cnt[sub] ;
    }
    if (ok) {
      cout << l ;
      break ;
    }
  }
  return 0 ;
}