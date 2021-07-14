/**
 *    author:  Tanbin_Hasan
 *    created: 14.07.2021 23:04:02
**/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  int64_t n ;
  cin >> n ;
  int64_t odd = 0 , even = 0 ;
  for (int64_t i = 0 ; i < n ; ++i) {
    int64_t x ;
    cin >> x ;
    ((x & 1) ? (++odd) : (++even)) ;
  }
  int64_t grp = 0 ;
  bool ok = false ;
  while (1) {
    ok ^= true ;
    if (ok) {
      if (even) {
        ++grp ;
        --even ;
      } else if (odd > 1) {
        ++grp ;
        odd -= 2 ;
      } else {
        break ;
      }
    } else {
      if (odd) {
        ++grp ;
        --odd ;
      } else {
        break ;
      }
    }
  }
  cout << grp - (odd > 0) ;
  return 0 ;
}