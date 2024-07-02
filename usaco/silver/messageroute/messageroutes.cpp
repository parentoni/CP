#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;
const ll MAX_N = 10e5;

ll n, m;
vl computers[MAX_N];
pair<bool, ll> inqueue[MAX_N]; //visited, parent
queue<ll> q;

void bfs() {
  q.push(0);
  inqueue[0] = {true, 0};

  while(!q.empty()){
    for (auto u: computers[q.front()]){
      if (inqueue[u].first) continue;
      q.push(u);
      inqueue[u] = {true, q.front()};
    }
    q.pop();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n >> m;
  for (int i=0;i<m;i++){
    ll a, b;
    cin >> a >> b; --a; --b;
    computers[a].push_back(b);computers[b].push_back(a);
  }

  bfs();
  if (!inqueue[n - 1].first) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vl path;
  ll p = n-1;

  path.push_back(p+1);
  while(p != 0){
    path.push_back(inqueue[p].second + 1);
    p = inqueue[p].second;
  }
  
  cout << path.size() << endl;
  for (int i=path.size()-1;i>=0;i--) cout << path[i] << " ";
  cout << endl;

}
