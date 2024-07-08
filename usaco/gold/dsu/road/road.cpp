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

ll n,m, father[MAX_N], height[MAX_N];
ll el, mc;

// flatten
ll find(ll x) {
  if (father[x] != x) {
    father[x] = find(father[x]);
  }

  return father[x];
}

void unite(ll x, ll y) {
  ll a = find(x), b = find(y);

  if (a == b) return; 
  el--;
  if (height[a] > height[b]) {
    father[b] = a;
    height[a] += height[b];
  } else {
    father[a] = b;
    height[b] += height[a];
  }


  mc = max(mc, max(height[a], height[b]));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>> n >> m;
  el = n; mc=1;
  for (int i=0;i<n;i++) {father[i] = i; height[i] = 1;}

  for (int i=0;i<m;i++) {
    ll a, b; cin >> a >> b; a--;b--;
    unite(a,b);
    cout << el << " " << mc << endl;

  }

}
