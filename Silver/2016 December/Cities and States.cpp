/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: citystate
      LANG: C++
      CREATED: 08.07.2021 20:22:24
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("citystate.in" , "r" , stdin) ;
  freopen("citystate.out" , "w" , stdout) ;
  map<pair<string,string>,int64_t> cnt ;
  map<pair<string,string>,bool> mark ;
  int64_t n ;
  cin >> n ;
  while (n--) {
    string a , b ;
    cin >> a >> b ;
    ++cnt[{a.substr(0 , 2),b}] ;
  }
  int64_t ans = 0 ;
  for (auto &[x , y] : cnt) {
    auto &[a , b] = x ;
    if (mark[x] || mark[{b , a}]) {
      continue ;
    }
    if (a != b) {
      ans += y * cnt[{b , a}] ;
    }
    mark[x] = true ;
  }
  cout << ans ;
  return 0 ;
}