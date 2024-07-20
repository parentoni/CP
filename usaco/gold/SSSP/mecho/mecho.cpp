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
const ll MAX_N = 801;

ll dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

pll m, house;
ll n, s, db[MAX_N][MAX_N]; queue<pll> qb;
bitset<MAX_N> b[MAX_N]; // board;

bool possible(ll min) {

  vector<vl> d(n, vl(n, -1));
  queue<pll> q; q.push(m); d[m.f][m.s] = 0;

  if (min >= db[m.f][m.s]) return false;
  while(q.size()) {
    pll a = q.front(); q.pop();
    for (int i=0;i<4;i++) {
      ll x = a.f + dx[i], y = a.s + dy[i], c = d[a.f][a.s] + 1;
      if (x < 0 || x >= n || y < 0 || y >= n) continue;
      if (x == house.f && y == house.s) return true;
      if (!b[x][y] || d[x][y] != -1) continue;
      if (c/s + min >= db[x][y] && db[x][y] != -1) continue;
      d[x][y] = c;
      q.push({x,y});
    }
  }

  return false;
}

ll last_true(ll lo, ll hi, function<bool(ll)> f) {
  ll ans = -1;

  while(lo <= hi) {
    ll med = (hi-lo)/2 + lo;
    if (f(med)) {
      lo = med + 1;
      ans = med;
    } else {
      hi = med - 1;
    }
  }

  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for (auto &row: db) for (auto &el: row) el = -1;

  for (int i=0;i<n;i++) {
    string t; cin >> t;
    for (int j=0;j<n;j++) {
      b[i][j] = (t[j] == 'G' || t[j] == 'M');
      if (t[j] == 'H') {
        db[i][j] = 0;
        qb.push({i,j});
      }

      if (t[j] == 'M') {
        m = {i,j};
      } 

      if (t[j] == 'D') {
        house = {i,j};
      }
    }
  }

  while(qb.size()) {
    pll a = qb.front(); qb.pop();
    for (int i=0;i<4;i++) {
      ll x = a.f + dx[i], y = a.s + dy[i];
      if (x < 0 || x >= n || y < 0 || y >= n) continue;
      if (!b[x][y] || db[x][y] != -1) continue;
      db[x][y] = db[a.f][a.s]+1;
      qb.push({x,y});
    }
  }

  //for (int i=0;i<n;i++) {
  //  for (int j=0;j<n;j++) cout << db[i][j] << " ";
  //  cout << endl;
  //}

  cout << last_true(0, 1e17, possible) << endl;
}
