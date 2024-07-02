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
vl val;
ll n;

ll med(ll i, ll j) {
  return val[i + (j-i)/2];
}
bool possible(ll x) {

  
  ll fast = 1, slow = 0;
  while (fast < n && slow < n) {
    if (val[fast] < x) {
      fast++;
    } else if (med(slow,fast) < x) {
      slow++;
      if (slow == fast) fast++;
    } else {
       return true;
    }

  }
  return false;
}

ll last_true(ll lo, ll hi) {
  ll ans = -1;
  while(lo <= hi) {
    ll med = lo + (hi - lo) / 2;
    //cout << lo << " " << hi << " " << med << endl;
    if (possible(med)) {
      ans = med;
      lo = med - 1;
    } else {
      hi = med + 1;
    }
  }
  return ans;
}
void solve() {
  cin >> n;
  val.resize(n);
  for (auto &el: val) cin >> el;
  sort(all(val));

  cout << last_true(1, val.back() + 1) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  ll t; cin >> t;
  while(t--) solve();
}
