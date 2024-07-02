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

ll n, t;
vl machines;

ll first_true(ll lo, ll hi, function<bool(ll)> f) {

  while (hi > lo) {
    ll med = lo + (hi - lo) / 2;
    if (f(med)){
      hi = med;
    } else {
      lo = med+1;
    }

  }

  return hi;

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n >> t;
  machines.resize(n);
  for (auto &el: machines) cin >> el;

  cout << first_true(0, inf, [&](ll x){
    ll sum = 0;
    for (auto el: machines){
      sum += x / el;
      if (sum >= t) {
        return true;
      }
    }
    return false;

  }) << endl;
}
