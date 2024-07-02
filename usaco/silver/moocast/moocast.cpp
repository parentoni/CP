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
const ll MAX_N = 200;

ll n, y = 0, c =0;
vl cows[MAX_N];
bool visited[MAX_N];
vector<pair<pll, ll>> pos;

void dfs(ll i) {
  if (visited[i]) return;
  visited[i] = true;
  c++;

  for (auto u: cows[i]) {
    dfs(u);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("moocast");
  cin >> n;

  for (int i=0;i<n;i++){
    ll x,y,p;
    cin >> x >> y >> p;
    pos.push_back({{x,y}, p});
  }

  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      if (pow(pos[j].first.first - pos[i].first.first, 2)+ 
          pow(pos[j].first.second- pos[i].first.second, 2) 
        < pow(pos[i].second, 2)){
        cows[i].push_back(j);
      }

      if (pow(pos[i].first.first - pos[j].first.first, 2)+ 
          pow(pos[i].first.second- pos[j].first.second, 2) 
        < pow(pos[j].second, 2)){
        cows[j].push_back(i);
      }
    }
  }

  for (int i=0;i<n;i++){
    c = 0;
    fill(visited, visited + MAX_N, 0);
    dfs(i);
    y = max(y,c);
  }

  cout << y << endl;
}
