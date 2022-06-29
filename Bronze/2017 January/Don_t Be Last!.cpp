/*
      ID: Tanbin Hasan Ador [tanvirh5]
      TASK: notlast
      LANG: C++
      CREATED: 06.07.2021 20:05:16
*/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  freopen("notlast.in" , "r" , stdin) ;
  freopen("notlast.out" , "w" , stdout) ;
  map<string,int> ind ;
  vector<string> vs = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"} ;
  for (int i = 0 ; i < 7 ; ++i) {
    ind[vs[i]] = i ;
  }
  vector<pair<int64_t,string>> vp(7) ;
  int n ;
  cin >> n ;
  while (n--) {
    string s ;
    cin >> s ;
    int x ;
    cin >> x ;
    auto &[a , b] = vp[ind[s]] ;
    a += x ;
    b = s ;
  }
  sort(vp.begin() , vp.end()) ;
  string ans ;
  for (int i = 1 ; i < 7 ; ++i) {
    if (vp[i].first > vp[i - 1].first && ans.empty()) {
      ans = vp[i].second ;
    } else if (vp[i].first == vp[i - 1].first && !ans.empty()) {
      ans.clear() ;
      break ;
    }
  }
  cout << ((!ans.empty()) ? (ans) : ("Tie")) ;
  return 0 ;
}