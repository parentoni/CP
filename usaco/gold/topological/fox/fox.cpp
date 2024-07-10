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

ll n, state[26], indegree[26];
vl adj[26], top;
bool valid = true;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n; vector<string> s(n); for (auto &el: s) cin >> el;

  for (int i=0;i<n-1;i++) {
    ll a = 0;
    while(a < min(s[i].size(), s[i+1].size())) {
      if (s[i][a] != s[i+1][a]) {
        adj[s[i][a] - 'a'].push_back(s[i+1][a] - 'a');indegree[s[i+1][a]-'a']++;break;
      }
      a++;
    }

    if (a == min(s[i].size(), s[i+1].size()) && (s[i].size() > s[i+1].size())) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  queue<ll> q;
  for (int i=0;i<26;i++) {
    if (indegree[i] != 0) continue; 
    q.push(i);
  }

  while(q.size()) {
    ll a = q.front();
    q.pop();
    top.push_back(a);

    for (auto u: adj[a]) {
      indegree[u]--; if (indegree[u] == 0) q.push(u);
    }

  }


  if (top.size() < 26) {
    cout << "Impossible" << endl;
  } else {
    for (int i=0;i<26;i++) cout << (char)(top[i]+'a');
    cout << endl;
  }
}
