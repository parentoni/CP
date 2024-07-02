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

  ll x; cin >> x;
  ll ans = 0;
  for (int i=1;i*i<x;i++) {
    if (x % i == 0) ans += 2;
  }

  if (floor(sqrt(x)) * floor(sqrt(x)) == x) ans++;

  cout << ans << '\n';

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t;
  while(t--) {

    int x; cin >> x;
    int ans = 0;

    for (int i=1;i*i<x;i++) {
      if (x % i == 0) ans += 2;
    }

    if (floor(sqrt(x)) * floor(sqrt(x)) == x) ans++;

    cout << ans << '\n';
  }
}
