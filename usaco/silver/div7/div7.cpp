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
const ll mod = 1000000007;

ll n, m = 0;
vl v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("div7");
  cin >> n;
  v.resize(n+1);

  for (int i=1;i<=n;i++){
    int t;
    cin >> t;
    v[i] = v[i-1] + t;
  }

  for (ll i=1;i<n+1;i++){
    for (ll j=i+2;j<n+1;j++){
      if ((v[j] - v[i-1]) % 7 == 0){
        m = max(j-(i-1),m);
      }
    }
  }

  cout << m << endl;
}
