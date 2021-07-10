/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: div7
      LANG: C++
      CREATED: 10.07.2021 16:45:12
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("div7.in" , "r" , stdin) ;
  freopen("div7.out" , "w" , stdout) ;
  int64_t n ;
  cin >> n ;
  vector<int64_t> _(7 , n) ;
  vector<int64_t> __(7) ;
  int64_t sum = 0 , x ;
  for (int64_t i = 0 ; i < n ; ++i) {
    cin >> x ;
    sum += x ;
    sum %= 7 ;
    _[sum] = min(_[sum] , i) ;
    __[sum] = i ;
  }
  int64_t ans = 0 ;
  for (int64_t i = 0 ; i < 7 ; ++i) {
    ans = max(ans , __[i] - _[i]) ;
  }
  cout << ans ;
  return 0 ;
}