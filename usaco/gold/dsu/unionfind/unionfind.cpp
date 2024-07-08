#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// geometry
const double PI = 3.14159265358979323846;
double DEG_to_RAD (double d) {return d*PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MAX_N = 2 * 1e5;
ll n, q, p[MAX_N], h[MAX_N];

ll find(ll x) {
  if (p[x] != x) {
    p[x] = find(p[x]);
  }

  return p[x];
}

void unite(ll a, ll b) {
  ll roota = find(a), rootb = find(b);
  if (h[roota] > h[rootb]) {
    p[rootb] = roota;
    h[roota] = max(h[roota], h[rootb]+1);
  } else {
    p[roota] = rootb;
    h[rootb] = max(h[rootb], h[roota]+1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> q;
  for (int i=0;i<n;i++) {p[i] = i;h[i]=0;}
  while(q--) {
    ll a, b, c; cin >> a >> b >> c;
    if (a == 0) {
      unite(b,c);
    } else {
      cout << (find(b) == find(c)) << "\n";
    }

  }
}
