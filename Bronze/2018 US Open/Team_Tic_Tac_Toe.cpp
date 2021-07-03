/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: tttt
      LANG: C++
      CREATED: 03.07.2021 17:48:38
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("tttt.in" , "r" , stdin) ;
  freopen("tttt.out" , "w" , stdout) ;
  vector<string> vs(3) ;
  for (int64_t i = 0 ; i < 3 ; ++i) {
    cin >> vs[i] ;
  }
  int64_t one = 0 , two = 0 ;
  map<pair<int,int>,int64_t> cnt ;
  set<char> s ;
  s = {vs[0][0] , vs[1][1] , vs[2][2]} ;
  auto it = (s).begin() ;
  if ((int) s.size() == 1) {
    one += (cnt[{*it , -1}] == 0) ;
    ++cnt[{*it , -1}] ;
  } else if ((int) s.size() == 2) {
    pair<int,int> p = {*it , *(++it)} ;
    two += (cnt[p] == 0) ;
    ++cnt[p] ;
  }
  s = {vs[0][2] , vs[1][1] , vs[2][0]} ;
  it = (s).begin() ;
  if ((int) s.size() == 1) {
    one += (cnt[{*it , -1}] == 0) ;
    ++cnt[{*it , -1}] ;
  } else if ((int) s.size() == 2) {
    pair<int,int> p = {*it , *(++it)} ;
    two += (cnt[p] == 0) ;
    ++cnt[p] ;
  }
  for (int64_t i = 0 ; i < 3 ; ++i) {
    s = {vs[i][0] , vs[i][1] , vs[i][2]} ;
    it = (s).begin() ;
    if ((int) s.size() == 1) {
      one += (cnt[{*it , -1}] == 0) ;
      ++cnt[{*it , -1}] ;
    } else if ((int) s.size() == 2) {
      pair<int,int> p = {*it , *(++it)} ;
      two += (cnt[p] == 0) ;
      ++cnt[p] ;
    }
    s = {vs[0][i] , vs[1][i] , vs[2][i]} ;
    it = (s).begin() ;
    if ((int) s.size() == 1) {
      one += (cnt[{*it , -1}] == 0) ;
      ++cnt[{*it , -1}] ;
    } else if ((int) s.size() == 2) {
      pair<int,int> p = {*it , *(++it)} ;
      two += (cnt[p] == 0) ;
      ++cnt[p] ;
    }
  }
  cout << one << '\n' ;
  cout << two << '\n' ;
  return 0 ;
}