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
const ll MAX_N = 1000, MAX_X = 1e5;

vector<pair<int,int>> books; //p.first = price, p.second = pages.
ll n, x;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x; books.resize(n);
  vector<vector<int>> dp(n+1, vector<int>(x+1,0));

  for (auto &el: books) cin >> el.first;
  for (auto &el: books) cin >> el.second;

  for (int w=1;w<=n;w++) {
    for (int i=0;i<=x;i++) {
      if (i - books[w-1].first < 0) continue;
      
      dp[w][i] = max(dp[w][i], dp[w-1][i - books[w-1].first] + books[w-1].second);
      dp[w][i] = max(dp[w][i], dp[w-1][i]);
    }
  }


  cout << dp[n][x] << endl;

}
