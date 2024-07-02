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

void solve() {
  int r, c;
  cin >> r >> c;

  vector<set<char>> rows(1);
  vector<set<char>> cols(1);
  if (r > 1) rows.resize(2);
  if (c > 1) cols.resize(2);

  for (int i=0;i<r;i++){
    string row;
    cin >> row;
    for (int j=0;j<c;j++){
      if (j == 0) cols[0].insert(row[j]);
      if (j == c-1 && c != 1) cols[1].insert(row[j]);
      if (i == 0) rows[0].insert(row[j]);
      if (i == r-1 && r!=1) rows[1].insert(row[j]);
    }
  }

  bool wpossible = true, bpossible = true;

  for (int i=0;i<2;i++){
    if (i < c) {
      if (cols[i].size() == 1) {
        if (*(cols[i].begin()) == 'W') bpossible = false;
        else wpossible = false;
      }
    }

    if (i < r) {
      if (rows[i].size() == 1) {
        if (*(rows[i].begin()) == 'W') bpossible = false;
        else wpossible = false;
      }
    }
  }

  //cout << wpossible << " " << bpossible << endl;
  if (wpossible || bpossible) yes();
  else no();
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
