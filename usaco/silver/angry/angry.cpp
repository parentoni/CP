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

ll n, k;
vl cows;

bool possible(ll x) {

  ll u = 1, curr = 0;

  for (int i=0;i<n;i++){
    if (cows[i] - cows[curr] > 2*x) {
      u++; curr = i;
    }
  }

  return u <= k;
}

ll first_true (ll lo, ll hi, function<bool(ll)> f) {
  ll ans = -1;
  while(lo <= hi) {
    ll med = lo + (hi - lo) /2;
    if (f(med)) {
      ans = med;
      hi = med -1;
    } else {
      lo = med + 1;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("angry");

  cin >> n >> k; cows.resize(n);
  for (auto &el: cows) cin >> el;

  sort(all(cows));


  cout << first_true(0, 1e17, possible) << endl;
}
