#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define all(x) (x).begin(), (x).end()

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll mod = 1000000007;

ll n, y;
vector<bool> row, col;

void search(int i){
  if (i == n) {
    return ;
  }
  
}
void solve() {

  y = 0;
  cin >> n;
  row.resize(n);
  col.resize(n);

  fill(all(row),0);
  fill(all(col),0);

  search(0);
  cout << y << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while(t--){
    solve();
  }
}

