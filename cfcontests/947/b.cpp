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

vl chosen;
bool isdivisible(ll x) {
  for (auto el: chosen) 
    if (x % el == 0) return true;
  return false;
}

void solve() {
  chosen.resize(0);
  ll n; vl values;
  cin >> n; values.resize(n);
  for (auto &el: values) cin >> el;
  sort(all(values));

  for (int i=0;i<n;i++){
    if (!isdivisible(values[i])){
      if (chosen.size() >=2) {
        no(); return;
      }
      chosen.push_back(values[i]);
    }
  }

  yes();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  ll t; cin >> t;
  while(t--) {
    solve();
  }
}
