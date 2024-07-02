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
 * Add each node individually.
 *
 * If outdegree is possilby even, mark edges as added;
 * If after all edges are processed and there are non-marked edges, impossible.
 * */

ll n, m, marked = 0;
pair<int,pll> edge[2 * MAX_N]; // p.first -> the classification of the edge, 0 if non-processed, 1 if regular order, -1 if inversed.
vector<pll> adj[MAX_N]; // p.first -> adj, p.second -> edge index;

void mark_edges(ll node) {
  vl tomark;
  for (auto u: adj[node]) {
    if (edge[u.second].first == 0) tomark.push_back(u.second);
  }

  for (int i=0;i<tomark.size() / 2 * 2;i++) {
    if (edge[tomark[i]].first != 0) continue;
    if (edge[tomark[i]].second.second == node) edge[tomark[i]].first = 1;
    else edge[tomark[i]].first = -1;
    marked++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=0;i<m;i++){
    ll a,b; cin >> a >> b;
    adj[--a].push_back({--b,i});
    adj[b].push_back({a,i});
    edge[i] = {0, {a,b}};
  }
  
  for (int i=0;i<n;i++) mark_edges(i);

  cout << marked << endl;
  for (int i=0;i<m;i++){
    cout << edge[i].second.first + 1<< " " << edge[i].second.second + 1 <<  " " << edge[i].first << endl;
  }


}
