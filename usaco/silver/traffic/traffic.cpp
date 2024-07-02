#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pii = pair<int,int>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll MOD = 1000000007;

ll x,n;
set<ll> traffic_lights;
multiset<ll> gap;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> x >> n;

  ll global_max = 0;
  ll l = 0, r=x;

  traffic_lights.insert(0);
  traffic_lights.insert(x);

  gap.insert(x);

  for (int i=0;i<n;i++) {

    ll light; cin >> light;

    auto it = traffic_lights.upper_bound(light);

    auto a = it, b = it; b--;
    gap.erase(gap.find(*a - *b));
    gap.insert(*a - light);
    gap.insert(light - *b);
    traffic_lights.insert(light);

    cout << *(--gap.end()) << endl;
  }
}
