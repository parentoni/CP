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
const ll MAX_N = 1e5;

/**
 * n <= 1e5; m <= 2 * 1e5;
 * simplest possible case: binary tree; a->b && a->c;
 *
 * ---- first ---
 *  BFS on a arbitrary node. check wheter it has a possible even degree. If possible, mark the edge direction. Mark it as processed.
 *  Go to its neighbors. Check wheter is possible to create an even outdegree WITHOUT marked nodes. If possible, mark the edge direction. Mark it as processed.
 *
 *  IMPOSSIBLE: if some edge dosen't have a setted direction: impossible;
 *
 *
 *  WORKS on example case.
 *  WORKS on impossible (+1,3) case;
 *  WORKS on 4 edge simple case.
 * */

ll n, m, marked = 0;
pair<int,pll> edges[2* MAX_N]; // 0 if not processed. 1 if normal order. -1 if inverse order.
vector<pll> adj[MAX_N]; // p.first -> adj. p.second -> edge index;
bool visited[MAX_N]; // visited might be marked;
bool processed[MAX_N];
queue<ll> q;


// all nodes are connected;
void bfs(ll s) {

  visited[s] = true;
  q.push(s);

  while(!q.empty()){

    ll s = 0;
    for (auto u: adj[q.front()]){
      if (!processed[u.first]) s++;
    }

    if (s % 2 == 0 && s != 0) {
      for (auto u: adj[q.front()]){
        if (processed[edges[u.second].second.first] || processed[edges[u.second].second.second]) continue;
        if (edges[u.second].second.first == q.front()) edges[u.second].first = 1;
        else edges[u.second].first = -1;
        marked++;
      }
      processed[q.front()] = true;
    }

    // bfs 
    for (auto u: adj[q.front()]){
      if (!visited[u.first]) {
        visited[u.first] = true;
        q.push(u.first);
      }
    }

    q.pop();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i=0;i<m;i++){
    ll a, b; cin >> a >> b; 
    adj[--a].push_back({--b,i});
    adj[b].push_back({a,i});
    edges[i]  = {0, {a,b}};
  }

  bfs(0);


  for (int i=0;i<m;i++) {
    if (edges[i].first == 1) {
      cout << edges[i].second.first + 1<< " " << edges[i].second.second + 1 << " " << edges[i].first << endl;
    } else if (edges[i].first == -1) {
      cout << edges[i].second.second + 1<< " " << edges[i].second.first + 1<< " " << edges[i].first << endl;
    } else {
      cout << i << " IMPOSSIBLE" << endl;
    }

  }

}
