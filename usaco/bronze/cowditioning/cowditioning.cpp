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

ll n, m, min_all = INF;
vector<long> sub;
vector<ar<int, 3>> cows;
vector<ar<int, 4>> air;

void check() {
  ll st[100] = {0};
  
  ll money =0;
  for (auto el: sub) {
    for (int i=air[el][0];i<=air[el][1];i++){
      st[i] += air[el][2];
    }
    money+= air[el][3];
  }

  bool invalid = false;
  for (auto el: cows) {
    for (int i=el[0]; i<= el[1];i++) {
      if (st[i] < el[2]) invalid = true;
    }
  }
  if (!invalid) min_all= min(money, min_all);
}
void solve(int i) {
  if (i == m) {
    check();
    return;
  }

  solve(i+1);
  sub.push_back(i);
  solve(i+1);
  sub.pop_back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  cows.resize(n);
  air.resize(m);

  for (auto &el: cows) cin >> el[0] >> el[1] >> el[2];
  for (auto &el: air) cin >> el[0] >> el[1] >> el[2] >> el[3];

  solve(0);

  cout << min_all << endl;

}
