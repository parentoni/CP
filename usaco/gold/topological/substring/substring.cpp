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
const ll MAX_N = 3 * 1e5;

ll n, m, state[MAX_N+1];
vl adj[MAX_N+1], top;
ll dp[MAX_N+1][26], indegree[MAX_N+1];

bool valid =true;

string sub;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> sub;

  for (int i=0;i<m;i++) {
    ll a, b; cin >> a >> b;
    adj[a].push_back(b); indegree[b]++;
  }

  queue<ll> q;
  for (int i=1;i<=n;i++) {
    if (indegree[i] == 0) {
      dp[i][sub[i-1]-'a']++;
      q.push(i);
      state[i] = 1;
    }
  }

  while (q.size()) {
    ll a = q.front();
    q.pop();

    for (auto u: adj[a]){
      indegree[u]--;
      if (indegree[u] == 0) q.push(u);
    }

    top.push_back(a);
  }
  if (top.size() != n) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 1;
  for (int i=0;i<top.size();i++) {
    for (auto u: adj[top[i]]) {
      for (int c=0;c<26;c++) {
        dp[u][c] = max(dp[u][c], dp[top[i]][c] + (sub[u-1] - 'a' == c));
        //cout << dp[u][c] << " " << u << " " << (char)(c+'a') << " " << dp[top[i]][c] << endl;
        ans = max(ans, dp[u][c]);
      }
    }
  }
  cout << ans << endl;
}
