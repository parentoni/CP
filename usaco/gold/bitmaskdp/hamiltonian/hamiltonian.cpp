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
const ll MAX_N = 20;


ll n, m;
ll dp[1 << MAX_N][MAX_N];
vl radj[MAX_N];

string int_to_bit (ll i) {
  string s="";
  for (int j=floor(log2(i));j>=0;j--) {
    if (i & (1ll << j)) s+="1";
    else s += "0";
  }
  return s;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i=0;i<m;i++) {
    ll a, b; cin >> a >> b;
    radj[--b].push_back(--a);
  }

  dp[1][0] = 1;
  for (int mask=2;mask < (1 << n);mask++) {
    if ((mask & 1) == 0) continue; // guarantees that first city is in the path
    if (mask & (1 << (n-1)) && mask != ((1 << n)-1)) continue; // guarantees that all previous cities have been visited
    

    for (int end=0;end<n;end++) {
      if ((mask & (1 << end)) == 0) continue; // ensures that city is included in path


      int prev = mask - (1 << end);
      for (ll come: radj[end]) {

        if ((mask & (1 << come))) {
          dp[mask][end] += dp[prev][come];
          dp[mask][end] %= MOD;
        }
      }
    }
  }

  //for (int i=0;i<n;i++) {
  //  for (int mask=2;mask < (1 << n);mask++) {
  //    if ((mask & 1) == 0) continue; // guarantees that first city is in the path
  //    if (mask & (1 << (n-1)) && mask != ((1 << n)-1)) continue; // guarantees that all previous cities have been visited
  //    cout << dp[mask][i] << " ";
  //  }

  //  cout << endl;
  //}

  cout << dp[(1 << n) - 1][n-1] << endl;
}
