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
const ll mod = 1000000007;

ll n, x;
map<ll, int> pos;
set<ll> values;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i=0;i<n;i++) {
    ll t;
    cin >> t;
    if (values.count(x - t)) {
      cout << i+1 << " " << pos[x-t]+1 << endl;
      return 0;
    } else {
      values.insert(t);
      pos[t] = i;
    }
  }

  cout << "IMPOSSIBLE" << endl;
}

