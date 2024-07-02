#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll solve(ll n, ll k,unordered_map<char, pair<ll, ll>> m, ll i) {
  if (k == i) {
    ll s = 0;
    for (auto el: m){
      s = s + el.second.second * el.second.second;
    }
    return s;
  }
  
  ll max=0;
  char maxc;
  for (auto el: m) {
    if (el.second.first > max && el.second.second < el.second.first){
      max = el.second.first;
      maxc = el.first;
    }
  }

  m[maxc].second = m[maxc].second +1;
  return solve(n, k, m, i + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n,k;
  string s;
  cin >> n >> k >> s;
  unordered_map<char, pair<ll, ll>> m;
  for (auto el: s) {
    pair<ll,ll> p;
    if (m.count(el) ==0) {
      p.first = 1;
      p.second = 0;
      m[el] = p;
    } else {
      p.first = m[el].first + 1;
      m[el] = p;
    }
  }

  cout << solve(n, k, m, 0) << endl;
}

