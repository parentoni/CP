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

pair<int,int> pairs[3];
vector<ll> board;
ll n;


bool check() {

  ll space=0;
  for (int i=0;i<n*n;i++){
    if (board[i] == 0) continue;
    pair<int,int> ad = pairs[board[i]-1];

    for (int r=0;r<ad.second;r++){
      for (int c=0;c<ad.first;c++){
        if (i + c >= n) return false;
        if (
      }
    }
    space += ad.first * ad.second;
  }
  if (space!=n*n) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (auto &el: pairs) cin >> el.first >> el.second;
  n = max({pairs[0].first, pairs[0].second, pairs[1].first, pairs[1].second,pairs[2].first, pairs[2].second});

  board.resize(n*n);
  for (auto &el: board) el = 0;
  board[0] = 1;
  board[1] = 2;
  board[3] = 3;

  do {
    if (check()) return 0;
  } while(next_permutation(board.begin(),board.end()));
}
