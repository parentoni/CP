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

ll n, k;
vector<char> farmer;
char moves[3] = {'P', 'H', 'S'};

bool win(char a, char b){
  if (a == 'P' && b == 'H') return 1;
  if (a == 'H' && b == 'S') return 1;
  if (a == 'S' && b == 'P') return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("hps");

  cin >> n >> k; farmer.resize(n);
  for (auto &el: farmer) cin >> el;
  vector<vector<vl>> dp(n+1, vector<vl>(k+1, vl(3, 0)));

  for (int i=0;i<=n;i++) {
    for (int s=0;s<=k;s++) {
      for (int m=0;m<3;m++) {
        if (i + 1 <= n)dp[i+1][s][m] = max(dp[i+1][s][m], dp[i][s][m] + win(moves[m], farmer[i]));
        // move swipe
        for (int ms =0;ms<3;ms++) { 
          if (ms == m) continue;
          if (s + 1 <=k && i+1 <= n) dp[i+1][s+1][ms] = max(dp[i+1][s+1][ms], dp[i+1][s][m] + win(moves[ms], farmer[i]));
        }
      }
    }
  }

  cout << max({dp[n][k][0], dp[n][k][1], dp[n][k][2]}) << endl;

}
