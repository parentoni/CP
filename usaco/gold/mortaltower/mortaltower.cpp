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
const ll MAX_N = 1e5;

pair<ll, int> points[MAX_N + 1]; // p.second -> 1 if player, 2 if Friend.
ll n;
vector<bool> values;

void solve() {

  cin >> n; values.resize(n);
  for (int i=0;i<n;i++) {char t; cin >> t; values[i] = t == '1';}

  vector<vl> dp(n, vl(2, inf));

  dp[0][0] = values[0];
  dp[0][1] = values[0];

  for (int i=0;i<n;i++) {
    for (int who=0;who<2;who++) {
      for (int f=1;f<=2;f++) {
        if (i + f >= n) continue;
        ll add = values[i+1] + (f > 1?values[i+2]:0);
        dp[i+f][who] = min(dp[i+f][who], dp[i][!who] + add * who);
      }
    }
  }

  cout << min(dp[n-1][0], dp[n-1][1]) << endl; 

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  ll t; cin >> t;
  while(t--) solve();
}
