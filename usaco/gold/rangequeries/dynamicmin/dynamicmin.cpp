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
 
ll val[MAXN], segm_tree[2*MAXN-1]; // +1 to 1 index the array
ll n, q;

void recalculate(ll node) {
  segm_tree[node] = min(segm_tree[2*node+1], segm_tree[2*node+2]);
}

void build(ll node, ll left, ll right) {
 
  //cout << node << " - " << left << " " << right << endl;
  if (left == right) {
    segm_tree[node] = val[left-1];
  } else {
    ll middle = (right+left)/2;
    build(2*node+1, left, middle);
    build(2*node+2, middle+1, right);

    recalculate(node);
  }
}

ll query(ll node, ll left, ll right, ll x, ll y) {
  if (x <= left && right <= y) {
    return segm_tree[node];
  }

  ll ans = INF;
  ll middle = (right-left)/2+left;

  if (x <= middle) ans = min(ans, query(2*node+1, left, middle, x, y));
  if (y >= middle+1) ans = min(ans, query(2*node+2, middle+1, right, x, y));

  return ans;
}

void update(ll node, ll left, ll right, ll x, ll y) {
  if (left == right) {
    segm_tree[node] = y;
    return ;
  }

  ll middle = (right-left)/2+left;

  if (x <= middle) {
    update(2*node+1, left, middle, x, y);
  } else {
    update(2*node+2, middle+1, right, x, y);
  }

  recalculate(node);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q; 
  //for (int i=0;i<n;i++) cin >> val[i];

  for (int i=0;i<n;i++) {
    ll t; cin >> t; update(0, 1, n, i+1, t);
  }

  //build(0, 1, n);

  for (int i=0;i<q;i++) {
    ll a, b, c; cin >> a >> b >> c; 
    if (a == 1) update(0,1,n, b,c);
    else cout << query(0,1,n, b, c) << endl;
  }

}
