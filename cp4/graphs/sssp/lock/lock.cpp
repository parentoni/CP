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
ll l, u, r;

int add(int x, int y) {
  return (x + y) % 10000;
}

void solve(int c) {

  int distance[10000];
  memset(distance, -1, sizeof(distance));

  vector<int> b(r); for (auto &el: b) cin >> el; 

  queue<int> q; distance[l] = 0; q.push(l);
  while(q.size()) {
    int a = q.front();
    q.pop();
    if (a == u) {
      cout << "Case " << c << ": " << distance[u] << endl;
      return;
    }

    for (auto el: b) {
      int res = add(a, el); 
      if (distance[res] == -1) {
        distance[res] = distance[a]+1;
        q.push(res);
      }
    }
  }
  cout << "Case " << c << ": Permanently Locked" << endl;

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll i =1;
  while(cin >> l >> u >> r) {
    if (l+u+r == 0) break;
    solve(i);
    i++;
  }
}
