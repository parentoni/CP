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

void solve() {
  ll x,y, res;
  cin >> y >> x;

  ll ref = max(x,y);
  res = ref * ref (- ref + 1;
  if (ref %2 == 0) {
    res -= ref - y;
    res += ref - x; 
  } else {
    res += ref - y;
    res -= ref -x;
  }

  cout << res << endl;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  while (n--) {
    solve();
  }
}
