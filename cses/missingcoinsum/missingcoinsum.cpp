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

ll n;
vl coins;
vl prefix;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n; coins.resize(n); prefix.resize(n+1);

  for (auto &el: coins) cin >> el;
  sort(all(coins));

  for (int i=1;i<=n;i++){
    prefix[i] = coins[i-1] + prefix[i-1];
  }

  for (auto el: prefix) cout << el << " ";
  cout << endl;
}
