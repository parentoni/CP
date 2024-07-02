#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// geometry
const double PI = 3.14159265358979323846;
double DEG_to_RAD (double d) {return d*PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;


void solve() {
  ll n; vl s; cin >> n;

  for (int i=0;i<n;i++) {
    char t; cin >> t; s.push_back(t - '0');
  }

  if (n == 2) {cout << s[0] * 10+ s[1] << endl; return;}

  vl zeroes; 
  for (int i=0;i<n;i++) {
    if (s[i] == 0) zeroes.push_back(i);
  }

  // lock i as the start pos of double digit
  ll ans = INF;
  for (int i=0;i<n-1;i++) {
    ll dd = s[i] * 10 + s[i+1];

    bool zb = false, za = false;
    for (auto el: zeroes) {
      if (el < i) zb = true;
      if (el > i+1) za = true;
    }

    if (i == 0 && za) ans = 0;
    if (i == n-2 && zb) ans = 0;
    if (zb && za) ans = 0;
    if (ans == 0) break;

    ll a, b;

    if (i != 0) {
      a = s[0];
      for (int j=1;j<i;j++) {
        a = min(a + s[j], a * s[j]);
      }
    }

    if (i != n-2) {
      b = s[i+2];
      for (int j=i+3;j<n;j++) {
        b = min(b + s[j], b * s[j]);
      }
    }

    if (i == 0) ans = min(ans, min(dd * b, dd + b));
    else if (i == n-2) ans = min(ans, min(dd * a, dd + a));
    else  ans = min(ans, min({a * dd * b, a * dd + b, a + dd * b, a+dd+b}));
  }

  cout << ans << endl;


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  ll t; cin >> t; while(t--) solve();

}
