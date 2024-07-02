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
const ll MAX_N = 1000;

struct Ice {
  ll a, p;
};


ll n;
Ice fit = {0,0}, current;
bool icecream[MAX_N+2][MAX_N+2];
bool visited[MAX_N+2][MAX_N+2];

bool cmp(Ice a, Ice b) {
  if (a.a == b.a) return a.p < b.p;
  return a.a > b.a;
}

void flood(ll x, ll y) {
  if (x > n || x < 0 || y > n || y < 0) return;
  if (visited[x][y] || !icecream[x][y]) return;
  visited[x][y] = true;

  if (!icecream[x+1][y]) current.p++;
  if (!icecream[x-1][y]) current.p++;
  if (!icecream[x][y+1]) current.p++;
  if (!icecream[x][y-1]) current.p++;

  current.a++;
  flood(x+1,y); flood(x-1,y);
  flood(x,y+1); flood(x,y-1);

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("perimeter");
  //cout << cmp({10,0}, {5,0}) << " " << cmp({5,0}, {10,0}) << " " <<cmp({10,4}, {10,5}) << endl;

  cin >> n;
  for (int r=1;r<=n;r++){
    string l; cin >> l;
    for (int c=1;c<=n;c++){
      icecream[r][c] = l[c-1] == '#'? 1:0;
    }
  }

  for (int r=1;r<=n;r++){
    for (int c=1;c<=n;c++){
      if (visited[r][c]) continue;
      current = {0,0};
      flood(r, c);
      if (cmp(current, fit)) fit = current;
    }
  }

  cout << fit.a << " " << fit.p << endl;
}
