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

ll n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  vector<ll> val(n);

  for (auto &el: val) cin >> el;

  for (int i=0;i<n;i++){
    if (i != 0) val[i] = max({val[i-1] - m, val[i]});
    if (i!= n-1) val[i] = max({val[i+1] - m, val[i]});
  }

  for (int i=n-1;i>=0;i--){
    if (i != 0) val[i] = max({val[i-1] - m, val[i]});
    if (i!= n-1) val[i] = max({val[i+1] - m, val[i]});
  }

  for (auto el: val) cout << el << " ";
  cout << endl;
}
