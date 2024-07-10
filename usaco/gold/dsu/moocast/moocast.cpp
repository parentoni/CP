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
const ll MAX_N = 1000;

ll n, father[MAX_N+1], height[MAX_N+1];
vector<pair<ll, pll>> edges;
vector<pll> coord; 

ll find(ll x) {
  if (father[x] != x) {
    father[x] = find(father[x]);
  }
  return father[x];
}

bool unite(ll x, ll y) {
  ll a = find(x), b = find(y);
  if (a == b) return false;
  if (height[a] > height[b]) swap(a,b);
  father[b] = a;
  height[a] += b;
  return true;
}

ll dist(pll a, pll b) {
  return abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("moocast");

  cin >> n;
  for (int i=0;i<n;i++) {father[i] = i; height[i] = 1;}

  coord.resize(n); for(auto &el: coord) cin >> el.first >> el.second;
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      edges.push_back({dist(coord[i], coord[j]),{i, j}});
    }
  }
  sort(all(edges));

  for (auto el: edges) {
    if (unite(el.second.first, el.second.second)) {
      n--;
    }
    if (n == 1) {
      cout << el.first << endl;
      return 0;
    }


  }
}
