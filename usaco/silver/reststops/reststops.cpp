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

struct Stop{
  ll x, t;
};

ll l, n, rf, rb, y =0;
vector<Stop> mountain;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("reststops");

  cin >> l >> n >> rf >> rb;
  mountain.resize(n);

  for (auto &el: mountain) cin >> el.x >> el.t;

  sort(all(mountain), [](Stop &a, Stop &b){
    if (a.t == b.t) return a.x > b.x;
    return a.t > b.t;
  });

  ll last = 0;
  for (auto el:mountain){
    if (el.x < last) continue;

    ll diff = (el.x - last) * rf - (el.x - last) * rb;
    y += diff * el.t;
    last = el.x;
  }
  cout << y << endl;




}
