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

ll n, target, y =0;
vector<ll> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> target;
  v.resize(n);

  for (auto &el: v) cin >> el;

  ll prefix_sum = 0;
  map<ll, ll> map;
  map[0] = 1;

  for (auto el: v) {

    prefix_sum += el;
    //cout << el << " " << target << endl;

    y += map[prefix_sum - target];

    map[prefix_sum]++;
  }
  
  cout << y << endl;
}
