/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: breedflip
      LANG: C++
      CREATED: 13.07.2021 19:18:09
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("breedflip.in" , "r" , stdin) ;
  freopen("breedflip.out" , "w" , stdout) ;
  int64_t len ;
  cin >> len ;
  string a , b ;
  cin >> a >> b ;
  int64_t ans = 0 , cnt = 0 ;
  for (int64_t i = 0 ; i < len ; ++i) {
    if (a[i] != b[i]) {
      ++cnt ;
    } else {
      ans += (cnt != 0) ;
      cnt = 0 ;
    }
  }
  cout << ans + (cnt != 0) << '\n' ;
  return 0 ;
}