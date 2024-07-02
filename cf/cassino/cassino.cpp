#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define all(x) (x).begin(), (x).end()

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;

ll n, m, sum;
vector<vector<ll>> a;
void solve() {
  cin >> n >> m;
  sum = 0;
  a.resize(n);
  for (auto &el: a){
    el.resize(m);
    for (auto &in: el) cin >> in;
  }

  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      for (int c=0;c<m;c++){
        sum += abs(a[i][c] - a[j][c]);
      }
    }
  }

  cout << sum << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

