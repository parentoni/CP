#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll MOD = 1000000007;

ll n, v, cicles = 0;
const ll max_size = 10e5 + 1;
vl road[max_size]; // one index
queue<ll> process;
bool inqueue[max_size];
vl components;

void bfs(ll initial) {
  if (inqueue[initial]) return;
  components.push_back(initial); process.push(initial);
  inqueue[initial] = 1;

  while(!process.empty()){
    for (auto u: road[process.front()]){
      if (inqueue[u]) continue;
      process.push(u); inqueue[u] = true;
    }
    process.pop();
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> v;
  for (int i=0;i<v;i++){
    ll a,b;
    cin >> a >> b;
    road[a].push_back(b); road[b].push_back(a);
  }

  for (int i=1;i<=n;i++){
    bfs(i);
  }

  cout << components.size()-1 << endl;
  for (int i=0;i<components.size()-1;i++){
    cout << components[i] << " " << components[i+1] << endl;
  }

}
