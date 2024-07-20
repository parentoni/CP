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
const ll MAXR = (2000+1)*(2000+1);

int a, b, n, m, father[MAXR];
vector<int> horizontal, vertical;
vector<pair<int, pair<int,int>>> edge;

ll find(ll x) {
  if (father[x] != x) {
    father[x] = find(father[x]);
  }

  return father[x];
}

bool unite(ll x, ll y) {
  ll a = find(x), b = find(y);
  if (a == b) return false;
  if (rand() & 1) swap(a, b);
  father[b] = a;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("fencedin");

  cin >> a >> b >> n >> m;
  vertical.resize(n);
  horizontal.resize(m);

  for (auto &el: vertical) cin >> el;
  for (auto &el: horizontal) cin >> el;

  m++; horizontal.push_back(b);
  n++; vertical.push_back(a);

  sort(all(vertical));
  sort(all(horizontal));

  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {

      int index = i + j * n;
      int last_vertical = (i == 0? 0: vertical[i-1]);
      int last_horizontal = (j == 0? 0: horizontal[j-1]);

      if (j != m-1) edge.push_back({vertical[i] - last_vertical, {index, i + (j+1) * n}});
      if (i != n-1) edge.push_back({horizontal[j] - last_horizontal, {index, i+1 + j*n}});

    }
  }

  sort(all(edge));
  for (int i=0;i<n*m;i++) father[i] = i;

  ll ans = 0;

  for (auto el: edge) {
    if (unite(el.s.f, el.s.s)) {
      ans += el.f;
    }
  }
  cout << ans << endl;

}
