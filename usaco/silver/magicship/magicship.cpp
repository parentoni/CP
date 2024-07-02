#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;

map<char,int> dir_int = {{'U', 0},{'D', 1},{'L', 2},{'R', 3}};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

pll p, t, prefix, pll_e = {0,0};
ll n;
vector<pll> wind;

pll add_pll(pll a, pll b) {
  return {a.first + b.first, a.second + b.second};
}

pll multiply_pll(pll pair, ll times) {
  return {pair.first * times, pair.second * times};
}

pll wind_at_x(ll x){

  pll r = x / n > 0? multiply_pll(prefix, x/n) : pll_e;
  for (int i=0;i<x%n;i++){
    r.first += wind[i].first;
    r.second += wind[i].second;
  }

  return r;
}

bool possible(ll x) {
  pll w = wind_at_x(x);
  w = add_pll(w, p);
  
  return abs(t.first - w.first) + abs(t.second - w.second) <= x;
}

ll first_true(ll lo, ll hi, function<bool(ll)> f) {
  ll ans = -1;
  while(lo <= hi){
    ll med = lo + (hi-lo)/2;
    if (f(med)) {
      ans = med;
      hi = med - 1;
    } else {
      lo = med + 1;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> p.first >> p.second >> t.first >> t.second >> n;
  string temp; cin >> temp;

  for (int i=0;i<n;i++){
    wind.push_back({dx[dir_int[temp[i]]], dy[dir_int[temp[i]]]});
  }

  for (auto el: wind) {
    prefix.first += el.first;
    prefix.second += el.second;
  }
  
  cout << first_true(0, 1e17, possible) << endl;
}
