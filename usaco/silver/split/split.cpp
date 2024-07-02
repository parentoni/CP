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

ll n;
vector<pll> field;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n;
  field.resize(n);
  for (auto &el: field) cin >> el.first >> el.second;
  
    
}
