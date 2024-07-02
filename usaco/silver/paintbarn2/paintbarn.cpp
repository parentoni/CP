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

const int SIZE = 8;

ll barn[SIZE][SIZE];
ll n, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("paintbarn");

  cin >> n >> k;

  for (int i=0;i<n;i++){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    barn[x1][y1]++; barn[x2][y2]++;
    barn[x1][y2]--;barn[x2][y1]--;
  }

  for (int i=0;i<SIZE;i++){
    for (int j=0;j<SIZE;j++){
      if (i>0) barn[i][j] += barn[i-1][j];
      if (j>0) barn[i][j] += barn[i][j-1];
      if (i>0&&j>0) barn[i][j] -= barn[i-1][j-1];
    }
  }

  int c = 0;
  for (auto &row: barn){
    for (auto &el: row) {cout << el-2 << " ";el == k?c++:c+=0;};
    cout << endl;
  }

  cout << c << endl;
}
