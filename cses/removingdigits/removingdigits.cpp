#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;
const ll MAX_N = 1e6;

ll n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n;
  vl dp(n + 1, inf);
  dp[n] = 0;
  
  for (int i=n;i>0;i--) {
    ll cp = i;
    while(cp != 0) {
      if (i - cp % 10 < 0) continue;
      dp[i - cp % 10] = min(dp[i-cp % 10], dp[i] + 1);
      cp /= 10;
    }
  }

  cout << dp[0] << endl;
}
