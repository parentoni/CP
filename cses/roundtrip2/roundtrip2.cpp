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
vl trip[MAX_N+1];
int status[MAX_N+1] = {0};
vl processing;
bool found = false;

void dfs(ll i){
  if (status[i] != 0) return;

  status[i] = 1;
  processing.push_back(i);

  for (auto u: trip[i]){
    if (status[u] == 1){

      vl seq;
      seq.push_back(u);
      while(processing.back() != u){
        seq.push_back(processing.back());
        processing.pop_back();
      }
      seq.push_back(u);

      cout << seq.size() << endl;
      found = true;
      for (auto el: seq) cout << el << " ";
      cout << endl;

    
      return;
    } else if (status[u] == 0){
      dfs(u);
    }
    if (found) return;
  }

  processing.pop_back();
  status[i] = 2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n >> m;
  for (int i=0;i<m;i++){
    ll a,b; cin >> a >> b;
    trip[b].push_back(a);
  }

  for (int i=1;i<=n;i++) {
    if (found) break;
    if (status[i] == 0) dfs(i);
  }

  if (!found) cout << "IMPOSSIBLE" << endl;

}
