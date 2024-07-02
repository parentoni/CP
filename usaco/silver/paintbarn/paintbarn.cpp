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

ll n, k, y=0;
const ll SIZE = 1000;

ll diff[SIZE+1][SIZE+1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("paintbarn");

  cin >> n >> k;

  for (int i=0;i<n;i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    diff[y1][x1]++;
    diff[y2][x1]--;
    diff[y1][x2]--;
    diff[y2][x2]++;
  }

  for (int i=0;i<SIZE;i++){
    for (int j=0;j<SIZE;j++){
      if (i>0) diff[i][j] += diff[i-1][j];
      if (j>0) diff[i][j] += diff[i][j-1]; 
      if (j > 0 && i> 0) diff[i][j] -= diff[i-1][j-1];
      if (diff[i][j] == k) y++;
    }
  }

  cout << y << endl;
}
