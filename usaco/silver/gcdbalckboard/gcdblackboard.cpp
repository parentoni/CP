#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, y = 0;
  cin >> n;

  vl sights(n);
  vl gcd_prefix(n+1);
  vl gcd_suffix(n+1);

  for (auto &el: sights) cin >> el;

  for (int i=1;i<=n;i++) gcd_prefix[i] = gcd(gcd_prefix[i-1], sights[i-1]);
  for (int i=(n-1);i>=0;i--) gcd_suffix[i] = gcd(gcd_suffix[i+1], sights[i]);

  for (int i=1;i<=n;i++){
    y = max(y, gcd(gcd_prefix[i-1], gcd_suffix[i]));
  }

  cout << y << endl;

}
