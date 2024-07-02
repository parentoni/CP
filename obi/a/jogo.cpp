#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

const ll MAX_N = 50;
ll dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n, q;

bool board[52][52];
void solve(ll x) {
  if (x == 0) {

    for (int r=1;r<=n;r++) {
      for (int c=1;c<=n;c++) cout << board[r][c];
      cout << endl;
    }

    return ;
  }

  bool new_board[52][52];

  for (int r=1;r<=n;r++){
    for (int c=1;c<=n;c++) {
      ll v = 0;

      for (int i=0;i<8;i++) {
        if (board[r+dx[i]][c+dy[i]]) v++;
      }

      if (board[r][c]) {
        if (v == 2 || v == 3) new_board[r][c] = true;
        else new_board[r][c] = false;
      } else {
        if (v == 3) new_board[r][c] = true;
        else new_board[r][c] = false;
      }
    }
  }

  for (int r=1;r<=n;r++) {
    for (int c=1;c<=n;c++) board[r][c] = new_board[r][c];
  }

  solve(x-1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> q;
  for (int r=1;r<=n;r++) {
    string t; cin >> t;
    for (int c=1;c<=n;c++) board[r][c] = t[c-1] == '1';
  }

  //for (int r=1;r<=n;r++) {
  //  for (int c=1;c<=n;c++) cout << board[r][c] << " ";
  //  cout << endl;
  //}
  
  solve(q);
}

