#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'
#define f first
#define s second

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
const ll MAXN = 2e5;

ll n, q, fenwick[MAXN+1];

ll length(ll x) {
  return x & -x;
}

void update(ll pos, ll val) {
  for (;pos <= n; pos += (pos & -pos)) fenwick[pos] += val;
  //while(pos <= n) {
  //  fenwick[pos] += val; 
  //  pos += length(pos);
  //}
}

ll query(ll pos) {
  ll s = 0;
  for (;pos > 0; pos -= (pos & -pos)) s += fenwick[pos];
  //while(pos > 0) {
  //  s += fenwick[pos];
  //  pos -= length(pos);
  //}

  return s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;

  for (int i=0;i<n;i++) {
    ll t; cin >> t; update(i+1, t);
  }

  for (int i=0;i<q;i++) {
    ll a, b, c; cin >> a >> b >> c;
    if (a == 2) cout << query(c) - query(b-1) << endl;
    else {
      update(b, c - (query(b) - query(b-1)));
    }
  }
}
