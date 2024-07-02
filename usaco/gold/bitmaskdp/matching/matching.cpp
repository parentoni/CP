#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'

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
bool compat[21][21];
ll dp[1 << 21];

string int_to_string(int x) {
  string t;
  for (int i=floor(log2(x));i>=0;i--) {
    if (x & (1 << i)) t+= '1';
    else t += '0';
  }

  return t;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      char t; cin >> t;
      compat[i][j] = t == '1';
    }
  }

  dp[0] = 1;
  for (int i=0;i<(1<<n);i++) {
    ll p = __builtin_popcount(i);
    for (int w=0;w<n;w++) {
      if (i & (1 << w) || !compat[p][w]) continue;
      dp[i | (1 << w)] += dp[i];
      dp[i | (1 << w)] %= MOD;
    }
  }

  for (int i=0;i<(1<<n);i++) {
    cout << int_to_string(i) << " " << dp[i] << endl;
  }

  cout << dp[(1 << n) - 1] << endl;
}
