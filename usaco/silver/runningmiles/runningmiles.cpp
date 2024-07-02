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

  ll n, y =0; cin >> n;
  vl val(n);
  for (auto &el: val) cin >> el;

  vl suf(n+1), pre(n+1);

  for (int i=1;i<=n;i++){
    pre[i] = max(pre[i-1], val[i-1]);
  }

  for (int i=n-1;i>=0;i--){
    suf[i] = max(suf[i+1], val[i]);
  }


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--) {
    solve();
  }
}

