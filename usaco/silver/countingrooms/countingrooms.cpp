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
const ll MAX_N = 1000;

ll n, m, y =0;
bool room [MAX_N][MAX_N];
bool visited [MAX_N][MAX_N];

void flood(ll x, ll y){
  if (x < 0 || y < 0) return;
  if (visited[x][y] || x >= n || y >= m || !room[x][y]) return;
  visited[x][y] = 1;
  flood(x+1,y); flood(x-1,y);
  flood(x,y+1); flood(x,y-1);

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> m;

  for (int r=0;r<n;r++){
    string l; cin >> l;
    for (int c=0;c<m;c++){
      room[r][c] = (l[c] == '#'?0:1);
    }
  }

  for (int r=0;r<n;r++){
    for (int c=0;c<m;c++){
      if (!visited[r][c] && room[r][c])y++;
      flood(r,c);
    }
  }

  cout << y << endl;

}
