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

ll n, m, nodes=0, last_i;

bool visited[MAX_N], reversed = false;
vl flights[MAX_N], flights_reversed[MAX_N];
vl components;


void dfs(ll i) {
  if (visited[i]) return;
  visited[i] = 1;
  nodes++;

  for (auto u: reversed?flights_reversed[i]:flights[i]){
    dfs(u);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  
  for (int i=0;i<m;i++){
    ll a,b;
    cin >> a >> b;
    a--;b--;
    flights[a].push_back(b);
    flights_reversed[b].push_back(a);
  }

  for (int i=0;i<n;i++){
    if (visited[i]) continue;
    dfs(i);
    components.push_back(i);
  }

  if (components.size() != 1) {
    cout << "NO" << endl;
    cout << components[0] + 1 << " " << components[1] + 1 << endl;
  } else {

    fill(visited, visited + MAX_N, 0);
    nodes = 0; reversed = true; components ={};

    for (int i=0;i<n;i++){
      if (visited[i]) continue;
      dfs(i);
      components.push_back(i);
    }

    if (components.size() != 1) {
          cout << "NO" << endl;
          cout << components[1] + 1 << " " << components[0] + 1 << endl;
    } else cout << "YES" << endl;
  }


  //if (components.size() == 1) cout << "YES" << endl;
  //else cout <<"NO" << endl << components[0] << " " << components[1] << endl;

}
