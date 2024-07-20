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
const ll MX = 4e5 + 5;

ll n, q, a[MAXN], fenwick[MX];
vector<pll> upd, que;
vector<pair<char, pll>> allq;

vl compression;

void update(ll x, ll i) {
  for (;x <= MX;x += (x & -x)) fenwick[x] += i;
}

void updatecc(ll x, ll i) {
  ll ind = upper_bound(all(compression), x) - compression.begin();
  update(ind,i);
}


ll query(ll x) {
  ll s = 0;
  for (;x;x -= (x&-x)) s += fenwick[x];
  return s;
}

ll querycc(ll x) {
  ll ind = upper_bound(all(compression), x) - compression.begin();
  return query(ind);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q; 

  for (int i=0;i<n;i++) {
    ll t; cin >> t; a[i] = t;
    compression.push_back(t);
  }

  for (int i=0;i<q;i++) {
    char a; ll b, c; cin >> a >> b >> c;
    allq.push_back({a, {b,c}});
    if (a == '!') {compression.push_back(c);}

  }

  sort(all(compression));
  compression.erase(unique(all(compression)), compression.end());

  for (int i=0;i<n;i++) {
    updatecc(a[i], 1);
  }

  for (auto el: allq) {
    el.s.f--;
    if (el.f == '?') {
      cout << querycc(el.s.s) - querycc(el.s.f) << endl;
    } else {
      updatecc(a[el.s.f], -1);
      a[el.s.f] = el.s.s; 
      updatecc(el.s.s, 1);
    }
  }
}
