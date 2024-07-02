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
const ll MAX_N = 100;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

ll n,k,r, curr_cow = 0;
bool field[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pll> roads[MAX_N][MAX_N];
vl components;


void dfs(ll r, ll c) {
  if (r >= n || r < 0 || c >= n || c < 0) return;
  if (visited[r][c]) return;
  visited[r][c] = true;
  if (field[r][c]) curr_cow++;


  for (int i=0;i<4;i++) {
    bool valid = true;
    for (auto road: roads[r][c]) {
      if (road.first == r + dx[i] && road.second == c + dy[i]) valid = false;
    }


    if (valid) dfs(r + dx[i], c + dy[i]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  setio("countcross");
  
  cin >> n >> k >> r;
  for (int i=0;i<r;i++) {
    ll r,c,rb,cb; cin >> r >> c >> rb >> cb;
    r--;c--;rb--;cb--;
    roads[r][c].push_back({rb,cb});
    roads[rb][cb].push_back({r,c});
  }

  for (int i=0;i<k;i++) {
    ll r,c; cin >> r >> c;
    r--;c--;
    field[r][c] = true;
  }


  for (int r=0;r<n;r++){
    for (int c=0;c<n;c++){
      if (visited[r][c]) continue;
      //cout << r << " " << c << endl;
      curr_cow = 0;
      dfs(r,c);
      components.push_back(curr_cow);
    }
  }

  ll a = 0;
  for (int i=0;i<components.size();i++){
    for (int j=i+1;nj<components.size();j++){
      a += components[i] * components[j];
    }
  }

  cout << a << endl;
}
