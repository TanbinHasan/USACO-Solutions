/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: herding
      LANG: C++
      CREATED: 13.07.2021 01:40:49
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("herding.in" , "r" , stdin) ;
  freopen("herding.out" , "w" , stdout) ;
  int64_t a , b , c ;
  cin >> a >> b >> c ;
  int64_t mx = max(llabs(a - b) , llabs(b - c)) - 1 ;
  if (a + 1 == b && b + 1 == c) {
    cout << 0 << '\n' ;
  } else if (a + 2 == b || b + 2 == c) {
    cout << 1 << '\n' ;
  } else {
    cout << 2 << '\n' ;
  }
  cout << mx << '\n' ;
  return 0 ;
}