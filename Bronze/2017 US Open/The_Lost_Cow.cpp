/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: lostcow
      LANG: C++
      CREATED: 05.07.2021 00:55:03
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("lostcow.in" , "r" , stdin) ;
  freopen("lostcow.out" , "w" , stdout) ;
  int64_t x , y ;
  cin >> x >> y ;
  bool sign = (x <= y) ;
  int64_t pw = 1 ;
  int64_t ans = 0 ;
  while (1) {
    if ((sign && x + pw >= y) || (!sign && x + pw <= y)) {
      ans += llabs(x - y) ;
      cout << ans ;
      break ;
    }
    pw *= -2 ;
    ans += llabs(pw) ;
  }
  return 0 ;
}