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
const ll MAX_N = 7489;

ll dp[MAX_N+1]; 
ll coins[5] = {1,5,10,25,50};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  dp[0] = 1;
  for (auto el: coins) {
    for (int i=1;i<=MAX_N;i++) {
      if (i - el < 0) continue;
      dp[i] += dp[i-el];
    }
  }

  ll q; while(cin >> q) cout << dp[q] << endl;
}
