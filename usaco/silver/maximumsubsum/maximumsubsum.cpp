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

  ll n;
  cin >> n;

  vl values(n+1);

  for (int i=1;i<=n;i++) {
    ll t;
    cin >> t;
    ll val = values[i-1] + t;

    values[i] = values[i-1] + t;
  }

  
  ll seen_min = values[0], seen_max = values[1];

  for (int i=1;i<=n;i++){

    seen_max = max(seen_max, values[i] - seen_min);
    seen_min = min(seen_min, values[i]);
  }
  cout << seen_max << endl;

}
