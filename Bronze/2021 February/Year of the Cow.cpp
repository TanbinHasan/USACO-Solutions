/**
 *    author:  Tanbin_Hasan
 *    created: 06.07.2021 22:39:28
**/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  map<string,int> ind ;
  vector<string> vs = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"} ;
  for (int i = 0 ; i < 12 ; ++i) {
    ind[vs[i]] = i ;
  }
  map<string,int> year ;
  year["Bessie"] = 12000 ;
  int n ;
  cin >> n ;
  while (n--) {
    vector<string> s(8) ;
    for (auto &i : s) {
      cin >> i ;
    }
    if (s[3] == "previous") {
      int mod = year[s.back()] % 12 ;
      int cur = ((mod > ind[s[4]]) ? (mod - ind[s[4]]) : (mod + 12 - ind[s[4]])) ;
      year[s.front()] = year[s.back()] - cur ;
    } else {
      int mod = year[s.back()] % 12 ;
      int cur = ((mod < ind[s[4]]) ? (ind[s[4]] - mod) : (12 - mod + ind[s[4]])) ;
      year[s.front()] = year[s.back()] + cur ;
    }
  }
  cout << abs(year["Bessie"] - year["Elsie"]) ;
  return 0 ;
}