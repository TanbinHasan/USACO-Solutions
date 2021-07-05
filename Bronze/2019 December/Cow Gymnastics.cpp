/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: gymnastics
      LANG: C++
      CREATED: 05.07.2021 02:08:35
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("gymnastics.in" , "r" , stdin) ;
  freopen("gymnastics.out" , "w" , stdout) ;
  int k , n ;
  cin >> k >> n ;
  int ans = 0 ;
  map<pair<int,int>,int> cnt ;
  for (int t = 0 ; t < k ; ++t) {
    vector<int64_t> ar(n) ;
    for (auto &i : ar) {
      cin >> i ;
    }
    for (int i = 0 ; i < n ; ++i) {
      for (int j = i + 1 ; j < n ; ++j) {
        int a = min(ar[i] , ar[j]) ;
        int b = max(ar[i] , ar[j]) ;
        if (ar[i] > ar[j]) {
          ++cnt[{a , b}] ;
        } else {
          --cnt[{a , b}] ;
        }
        ans += (abs(cnt[{a , b}]) == k) ;
      }
    }
  }
  cout << ans ;
  return 0 ;
}