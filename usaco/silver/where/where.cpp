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
const ll MAX_N = 20;

ll n, field[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
ll colors[26];


ll dx[4] = {1,-1,0,0};
ll dy[4] = {0, 0, 1,-1};

pll bound_l, bound_r;
bool contained_rectangle(pll a1, pll a2, pll b1, pll b2) {
  return (a1.first >= b1.first && a1.second >= b1.second && a2.first <= b2.first && a2.second <= b2.second);
}

ll curr_cor;
void dfs(ll x, ll y) {
  if (x < bound_l.first || y < bound_l.second) return;
  if (x > bound_r.first || y > bound_r.second) return;
  if (visited[x][y]) return;
  if (field[x][y] != curr_cor) return;
  visited[x][y] = true;

  for (int i=0;i<4;i++){
    dfs(x + dx[i], y + dy[i]);
  }


}
bool is_pcl(pll a, pll b) {
  for (auto &row: visited) fill(row, row + MAX_N, 0);
  fill(colors, colors+26, 0);
  bound_l = a; bound_r = b;

  for (int r=a.first;r<=b.first;r++){
    for (int c=a.second;c<=b.second;c++){
      if (visited[r][c]) continue;
      colors[field[r][c]]++;
      curr_cor = field[r][c];
      dfs(r,c);
    }
  }

  ll col_count = 0;
  bool col_one=false, col_two=false;
  for (int i=0;i<26;i++){
    if (colors[i] != 0) col_count++; 
    if (colors[i] == 1) col_one=true;
    if (colors[i] > 1) col_two=true;
  }

  return col_count == 2 && col_one && col_two;
}

vector<pair<pll,pll>> pcls;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("where");
  cin >> n;
  
  for (int r=0;r<n;r++){
    string t; cin >> t;
    for (int c=0;c<n;c++){
      field[r][c] = (int)t[c] - 'A';
    }
  }

  for (int x1=0;x1<n;x1++){
    for (int y1=0;y1<n;y1++){
      for (int x2=0;x2<n;x2++){
        for (int y2=0;y2<n;y2++){
          if (is_pcl({y1,x1},{y2,x2})) {
            //cout << "hey" << endl;
            bool should = true;
            for (auto el: pcls) {
              if (contained_rectangle({y1,x1},{y2,x2}, el.first, el.second)) should = false;
            }

            if (should == true) {
              vector<pair<pll,pll>> new_pcls;
              for (auto el: pcls) {
                if (!contained_rectangle(el.first, el.second,{y1,x1},{y2,x2})) new_pcls.push_back(el);
              }
              new_pcls.push_back({{y1,x1},{y2,x2}});
              pcls = new_pcls;
            }

          }
        }
      }
    }
  }

  
  cout << pcls.size() << endl;
}
