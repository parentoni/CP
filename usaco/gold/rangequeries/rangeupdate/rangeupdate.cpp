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

ll n, q;
ll diff[MAXN], segm_tree[4*MAXN];

void recalculate(ll node) {
  segm_tree[node] = segm_tree[2*node+1] + segm_tree[2*node+2];
}



/**
 * void update(ll node, ll left, ll right, ll x, ll y) {
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

void update(ll node, ll left, ll right, ll x, ll y) {
  if (right == left) {
    segm_tree[node] += y;
    return ;
  }

  ll middle = (right-left)/2 + left;
  if (x <= middle) update(2*node+1, left, middle, x, y);
  else update(2*node+2, middle+1, right, x, y);
  
  recalculate(node);
}
 * */

void update(ll node, ll left, ll right, ll x, ll y) {
  if (left == right) {
    segm_tree[node] += y;
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

  vl a;
  cin >> n >> q; a.resize(n); for (auto &el: a) cin >> el;
  

  diff[0] = a[0];
  for (int i=1;i<n;i++) diff[i] = a[i] - a[i-1];
  for (int i=0;i<n;i++) {
    update(0,1,n+1, i+1, diff[i]);
  }


  for (int i=0;i<q;i++) {
    ll a, b; cin >> a >> b;
    if (a == 2) cout << query(0,1,n+1,1,b) << endl;
    else {
      ll c, d; cin >> c >> d; update(0,1,n+1,b,d); update(0,1,n+1,c+1,-d);
      //cout << a << " "  << b << " " << c << " " << d << " " << d ;
    }
  }

}
