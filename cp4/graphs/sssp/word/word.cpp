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

void solve(ll x) {
  if (x != 0) cout << endl;

  vector<string> s;
  string t; while(cin >> t) {
    if (t == "*") break;
    s.push_back(t);
  }

  map<string, vector<string>> adj;

  for (int i=0;i<s.size();i++) {
    for (int j=i+1;j<s.size();j++) {
      if (s[i].size() != s[j].size()) continue;
      int diff = 0;
      for (int c=0;c<s[i].size();c++) {
        diff += s[i][c] != s[j][c];
      }
      if (diff > 1) continue;
      adj[s[i]].push_back(s[j]);
      adj[s[j]].push_back(s[i]);
    }
  }

  string line;
  string a, b;
  cin.ignore();

  while(getline(cin, line)) {
    if (line.empty()) break;
    stringstream ss(line);
    ss >> a >> b;

    map<string,bool> visited; visited[a] = true;
    queue<pair<string, int>> q; q.push({a, 0});

    while(q.size()) {
      pair<string,int> curr = q.front();
      q.pop();

      if (curr.first == b) {
        cout << a << " " << b << " " << curr.second << endl;
      }
      for (auto u: adj[curr.first]) {
        if (visited[u]) continue;
        visited[u] = true;
        q.push({u, curr.second+1});
      }
    }

  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t; for (int i=0;i<t;i++) solve(i);
}
