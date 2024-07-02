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

  ll n, q;
  cin >> n >> q;

  vl values(n+1);

  for (int i=1;i<=n;i++){
    int t;
    cin >> t;
    values[i] = values[i-1] + t;
  }

  for (int i=0;i<q;i++){
    ll a,b;
    cin >> a >> b;
    cout << values[b] - values[a-1] << endl;
  }
}

