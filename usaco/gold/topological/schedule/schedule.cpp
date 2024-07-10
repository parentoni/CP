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
ll n, m, indegree[MAX_N+1];
vl adj[MAX_N+1];
bool inanswer[MAX_N+1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=0;i<m;i++) {
    ll a, b; cin >> a >> b;
    indegree[b]++; adj[a].push_back(b);
  }

  // kahn's algorithm
  queue<ll> q;
  for (int i=1;i<=n;i++) {
    if (indegree[i] == 0) q.push(i);
  }

  vl ans;
  while(q.size()){
    ll a = q.front();

    for (auto u: adj[a]) {
      indegree[u]--;
      if (inanswer[u]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
      if (indegree[u] == 0) q.push(u);
    }

    inanswer[a]=true;
    ans.push_back(a);
    q.pop();
  }

  if (ans.size() != n) cout << "IMPOSSIBLE";
  else for (auto el: ans) cout << el << " ";
  cout << endl;
}
