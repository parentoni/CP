#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;

bool col[8];
bool dia1[15];
bool dia2[15];
bool reserved[8][8];
ll y = 0;

void solve(ll i) {
  if (i == 8) {
    y++;
    return;
  }

  for (int j=0;j<8;j++) {
    if (col[j] || dia1[i+j] || dia2[j-i+8-1] || reserved[i][j]) continue;
    col[j] = dia1[i+j] = dia2[j-i+8-1] = 1;
    solve(i+1);
    col[j] = dia1[i+j] = dia2[j-i+8-1] = 0;
  }

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i=0;i<8;i++){
    string xl;
    cin >> xl;
    for (int j=0;j<8;j++) if (xl[j] == '*') reserved[i][j] = true;
  }

  solve(0);
  cout << y << endl;
}

