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

ll a[MAXN], segm_tree[2*MAXN-1]; // +1 to 1 index the array
ll n, q;

void recalculate(ll x) {
  segm_tree[x] = segm_tree[2*x+1] + segm_tree[2*x+2];
}

void build(ll x, ll left, ll right) {

  //cout << x << " - " << left << " " << right << endl;
  if (x < 0) return;
  if (left == right) {
    segm_tree[x] = a[left-1];
  } else {
    ll middle = (right-left)/2 + left;
    build(2*x+1, left, middle);
    build(2*x+2, middle+1, right);
    recalculate(x);
  }
}

void update(ll x, ll left, ll right, ll toupd, ll r) {
  if (right == left) {
    segm_tree[x] = r;
  } else {
    ll middle = (right-left)/2 + left;
    if (toupd <= middle) {
      update(2*x+1, left, middle, toupd, r);
    } else {
      update(2*x+2, middle+1, right, toupd, r);
    }

    recalculate(x);
  }
}

ll query(ll node, ll left, ll right, ll x, ll y) {
  if (x <= left && right <= y) {
    return segm_tree[node];
  }

  ll ans = 0;
  ll middle = (right-left)/2 + left;
  if (x <= middle) {
    ans += query(2*node+1, left, middle, x, y);
  }
  if (y >= middle+1) {
    ans += query(2*node+2, middle+1, right, x, y);
  }

  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i=0;i<n;i++) cin >> a[i];
  
  build(0, 1, n);

  for (int i=0;i<q;i++) {
    ll a, b, c; cin >> a >> b >> c;
    if (a == 1) update(0, 1, n, b, c);
    else cout << query(0,1,n,b,c) << endl;
  }



}
