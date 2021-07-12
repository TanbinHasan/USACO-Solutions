/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: sleepy
      LANG: C++
      CREATED: 13.07.2021 00:41:22
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("sleepy.in" , "r" , stdin) ;
  freopen("sleepy.out" , "w" , stdout) ;
  int64_t n ;
  cin >> n ;
  vector<int64_t> ar(n) ;
  for (auto &i : ar) {
    cin >> i ;
  }
  int64_t mn = 1 ;
  for (int64_t i = n - 2 ; i >= 0 ; --i) {
    if (ar[i + 1] - ar[i] > 0) {
      ++mn ;
    } else {
      break ;
    }
  }
  cout << n - mn ;
  return 0 ;
}