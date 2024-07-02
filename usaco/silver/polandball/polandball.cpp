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

ll n, s = 0;
set<ll> current;
vl val;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n; val.resize(n);
  for (auto &el: val) cin >> el;

  ll b = -1;
  for (int i=0;i<n;i++){
    b = max(val[i], b);
  
    if (i + 1 == b) {
      s++; b = -1;
    }
  }

  cout << s << endl;


}
