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
const ll MAX_N = 500;

ll a[MAX_N][MAX_N];
pll father[MAX_N][MAX_N];
ll height[MAX_N][MAX_N], cost[MAX_N][MAX_N];
ll n;

pll find(pll x) {
  if (father[x.first][x.second] != x) {
    father[x.first][x.second] = find(father[x.first][x.second]);
  }
  return father[x.first][x.second];
}

bool unite(pll x, pll y, ll c) {
  pll a = find(x), b = find(y);
  if (a == b) return false;

  if (height[a.first][a.second] > height[b.first][b.second]) swap(a,b);
  father[b.first][b.second] = a;
  cost[a.first][a.second] += cost[b.first][b.second] + c;
  height[a.first][a.second] += height[b.first][b.second];
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("tractor");
  cin >> n;

  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> a[i][j];
      father[i][j] = {i, j}; height[i][j] = 1;
    }
  }

  ll target = ceil(n*n/2);
  vector<pair<ll, pair<pll, pll>>> edges; // {cost, {a, b}};

  for (int i=0;i<n;i++) {
    for (int j=0;j<n-1;j++) {
      edges.push_back({ abs(a[i][j]-a[i][j+1]), {{i, j}, {i, j+1}}});
    }
  }

  for (int i=0;i<n-1;i++) {
    for (int j=0;j<n;j++) {
      edges.push_back({ abs(a[i][j]-a[i+1][j]), {{i, j}, {i+1, j}}});
    }
  }

  sort(all(edges));
  for (auto el: edges) {
    if (unite(el.second.first, el.second.second, el.first)) {
      pll a = find(el.second.first);
      if (height[a.first][a.second] >= target) {
        cout << el.first << endl;
        return 0;
      }
    }
  }

}
