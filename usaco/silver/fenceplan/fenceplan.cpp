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

ll n, m, y = inf;
map<ll, pll> pos;
vl cows[MAX_N];
bool visited[MAX_N];
queue<ll> q;
vector<pair<pll, pll>> network;

ll perimeter(pll a, pll b) {
  return abs(a.first - b.first) * 2 + abs(a.second - b.second) * 2;
}

void bfs(ll i){
  if (visited[i]) return;
  visited[i] = 1;
  q.push(i);

  pair<pll,pll> moo;
  moo.first = moo.second = pos[i];
  
  while(!q.empty()){
    for (auto u: cows[q.front()]){
      if (visited[u]) continue;
      visited[u] = true;
      moo.first.first = max(moo.first.first, pos[u].first);
      moo.first.second = max(moo.first.second, pos[u].second);
      moo.second.first = min(moo.second.first, pos[u].first);
      moo.second.second = min(moo.second.second, pos[u].second);
      q.push(u);
    }
    q.pop();
  }

  network.push_back(moo);

}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("fenceplan");

  cin >> n >> m;
  for (int i=0;i<n;i++){
    ll x,y;
    cin >> x >> y;
    pos[i] = {x,y};
  }

  for (int i=0;i<m;i++){
    ll a,b;
    cin >> a >> b;
    cows[a-1].push_back(b-1);
    cows[b-1].push_back(a-1);
  }

  for (int i=0;i<n;i++){
    bfs(i);
  }

  for (auto el: network){
    y = min(y, perimeter(el.first, el.second));
  }
  cout << y << endl;
}
