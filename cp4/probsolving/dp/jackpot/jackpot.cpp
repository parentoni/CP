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

ll n;

void solve() {
  vl dp(n+1, 0);

  for (int i=1;i<=n;i++) {
    ll t; cin >> t;
    dp[i] = dp[i-1] + t;
  }

  ll bi = 0, right = INF;
  for (int i=0;i<=n;i++) {

    right = min(right, dp[i]);
    bi = max(bi, dp[i] - right);
  }

  if (bi == 0) {
    cout << "Losing streak." << endl;
  } else {
    cout << "The maximum winning streak is " << bi << "." << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n) {
    if (n == 0) break;
    solve();
  }
}
