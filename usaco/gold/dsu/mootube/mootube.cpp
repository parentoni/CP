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
const ll MAX_N = 1e5;

ll n, q, father[MAX_N+1], height[MAX_N+1];

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
  height[a] += height[b];
  return true;
}

vector<pair<ll,pll>> edges; // {cost, {a,b}};
vector<pair<ll,pll>> queries; // {K, {video, index}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("mootube");

  cin >> n >> q;
  for (int i=0;i<n-1;i++) {
    ll a, b, c; cin >> a >> b >> c;
    edges.push_back({c, {a, b}});
  }
  sort(all(edges),greater<pair<ll,pll>>());

  for (int i=0;i<q;i++) {
    ll a, b; cin >> a >> b;
    queries.push_back({a, {b, i}});
  }
  sort(all(queries), greater<pair<ll,pll>>());

  for (int i=0;i<n;i++) {father[i] = i; height[i] = 1;}

  vl ans(q);
  ll left = 0;
  for (auto el: queries) {
    //cout << el.first << " " << el.second.first << endl;
    while (edges[left].first >= el.first && left < n) {
      unite(edges[left].second.first, edges[left].second.second);
      left++;
    }

    //cout << find(el.second.first) << endl;
    //cout << el.second.second  << " hey " << left  << endl;
    ans[el.second.second] = height[find(el.second.first)];
  }

  for (auto el: ans) cout << el-1 << endl;

}
