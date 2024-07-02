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
const ll MAX_N = 1000;

ll m, n, c;
vl money, adj[MAX_N+1];



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("time");


  cin >> n >> m >> c; money.resize(n);
  for (auto &el: money) cin >> el;

  vector<vl> dp(n+1, vl(1001, -1));

  for (int i=0;i<m;i++){
    ll a,b; cin >> a >> b; 
    adj[--a].push_back(--b);
  }

  dp[0][0] = 0;
    for (int k=0;k<1000;k++) {
    for (int i=0;i<n;i++) {
      if (dp[i][k] == -1) continue;

      for (auto u: adj[i]) {
        dp[u][k+1] = max(dp[u][k+1], dp[i][k] + money[u]);
      }
    }
  }

  ll m = 0;
  for (int i=0;i<=1000;i++) {
    m = max(m, dp[0][i] - c * i * i);
  }
  
  cout << m << endl;
}
