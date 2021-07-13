/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: outofplace
      LANG: C++
      CREATED: 14.07.2021 00:26:00
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("outofplace.in" , "r" , stdin) ;
  freopen("outofplace.out" , "w" , stdout) ;
  int64_t n ;
  cin >> n ;
  vector<int64_t> a(n) , b(n) ;
  for (int64_t i = 0 ; i < n ; ++i) {
    cin >> a[i] ;
    b[i] = a[i] ;
  }
  sort(b.begin() , b.end()) ;
  int64_t cnt = 0 ;
  for (int64_t i = 0 ; i < n ; ++i) {
    cnt += (a[i] != b[i]) ;
  }
  cout << cnt - (cnt != 0) ;
  return 0 ;
}