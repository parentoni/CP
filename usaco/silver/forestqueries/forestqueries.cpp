#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

ll n,q;

vector<vector<bool>> forest;
vector<vl> forest_sum;

ll prefix(ll x, ll y, ll val){
  return forest_sum[x-1][y] + forest_sum[x][y-1] - forest_sum[x-1][y-1] + val;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;

  forest_sum.resize(n+1);
  for (auto &el: forest_sum) el.resize(n+1);

  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++) {
      char tree;
      cin >> tree;
      bool val = tree == '*'? 1:0;
      forest_sum[i][j] = prefix(i,j,val);
    }
  }

  
  for (int i=0;i<q;i++){
    int y1,x1,y2,x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << forest_sum[y2][x2] - forest_sum[y2][x1-1] - forest_sum[y1-1][x2] + forest_sum[y1-1][x1-1] << endl;
    //cout << forest_sum[y2][x2] - forest_sum[y2][x1] - forest_sum[y1][x2] + forest_sum[y1][x1] << endl;
  }
}
