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

ll n, y=0;
map<ll, ll> sums_mod;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  ll c=0;
  sums_mod[0] = 1;
  for (ll i=0;i<n;i++){
    int t;
    cin >> t;
    c += t;
    sums_mod[(c% n+n) %n]++;
  }

  for (auto el: sums_mod) {
    y += el.second * (el.second - 1) / 2;
  }
  cout << y << endl;
}
