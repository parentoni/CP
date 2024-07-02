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

ll n, m;
pll a, b;

bool lab [MAX_N][MAX_N];
bool visited [MAX_N][MAX_N];
pair<char, pll> par [MAX_N][MAX_N];

vector<char> sq;
queue<pll> q;

void flood(ll x,ll y){


  q.push({x,y});
  while(!q.empty()){
    pll t = q.front();

    //cout << t.first << " " << t.second << " " << b.first << " " << b.second << endl;
    if (t.second - 1 >= 0) if (!visited[t.first][t.second-1] && lab[t.first][t.second-1]) {
      q.push({t.first, t.second-1});
      par[t.first][t.second-1] = {'L',t};
      visited[t.first][t.second-1] = true;
    }

    if (t.second + 1 < m) if (!visited[t.first][t.second+1] && lab[t.first][t.second+1]) {
      q.push({t.first, t.second+1});
      par[t.first][t.second+1] = {'R',t};
      visited[t.first][t.second+1] = true;
    }

    if (t.first -1 >= 0) if (!visited[t.first-1][t.second] && lab[t.first-1][t.second]) {
      q.push({t.first-1, t.second});
      par[t.first-1][t.second] = {'U',t};
      visited[t.first-1][t.second] = true;
    }

    if (t.first + 1 <n) if (!visited[t.first+1][t.second] && lab[t.first+1][t.second]) {
      q.push({t.first+1, t.second});
      par[t.first+1][t.second] = {'D',t};
      visited[t.first+1][t.second] = true;
    }


    visited[t.first][t.second] = true;
    if (t.first == b.first && t.second == b.second) return;
    q.pop();
  }

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n >> m;
  for (int r=0;r<n;r++){
    string l; cin >> l;
    for (int c=0;c<m;c++){
      if (l[c] == 'A') a = {r,c};
      if (l[c] == 'B') b = {r,c};
      lab[r][c] = l[c] == '#'?0:1;
    }
  }

  flood(a.first, a.second);
  if (visited[b.first][b.second]){

    pll cur = b;
    ll y = 0;
    while (cur != a) {
      y++;
      sq.push_back(par[cur.first][cur.second].first);
      cur = par[cur.first][cur.second].second;
    }

    cout << "YES" << endl <<  y << endl;
    for (int i=y-1;i>=0;i--){
      cout << sq[i];
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
