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

ll n, m, father[MAXN];

ll find(ll x) {
  if (father[x] != x) {
    father[x] = find(father[x]);
  }
  return father[x];
}

bool unite(ll x, ll y) {
  ll a = find(x), b = find(y);
  if (a == b) return false;
  if (rand()&1) swap(a,b);
  father[b] = a;
  return true;
}

void solve() {
  
  for (int i=0;i<n;i++) father[i] = i;
  using T = pair<ll, pll>; ll initial = 0, current = 0;
  vector<T> edges;
  for (int i=0;i<m;i++) {
    ll a, b, c; cin >> a >> b >> c;
    initial+=c;
    edges.push_back({c, {a,b}});
  }

  sort(all(edges));
  for (auto el: edges) {
    if (unite(el.s.f, el.s.s)) {
      current += el.f;
    }
  }

  cout << initial -  current << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n >> m) {
    if (n+m == 0) break;
    solve();
  }

}
