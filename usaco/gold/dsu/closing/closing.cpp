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

vl adj[MAX_N+1];
bool included[MAX_N+1];
ll n, m, father[MAX_N+1], height[MAX_N+1], merges = 0;

ll find(ll x) {
  if (father[x] != x) {
    father[x] = find(father[x]);
  }
  return father[x];
}

void unite(ll x, ll y) {
  ll a = find(x), b = find(y);
  if (a == b) return;

  merges++;
  if (rand() & 1) swap(a, b);
  father[b] = a;
  height[a] = height[b]+1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("closing");
  cin >> n >> m;

  for (int i=0;i<m;i++) {
    ll a, b;cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vl dels(n); for (auto &el: dels) cin >> el; reverse(all(dels));
  

  vector<string> ans;
  for (int i=0;i<n;i++) {father[i] = i;height[i]=0;}
  for (int i=0;i<n;i++) {
    ll a = dels[i];
    for (auto el: adj[a]) {
      if (included[el]) unite(a, el);
    }

    if (i == merges) ans.push_back("YES");
    else ans.push_back("NO");

    included[a] = true;
  }

  reverse(all(ans));
  for (auto el: ans) cout << el << "\n";

}
