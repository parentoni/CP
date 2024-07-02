#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
//void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

set<int> wv;
vector<int> w;
vector<int> sub;

ll n, min_all = 1e18, min_local;

void test() {

  ll px = 0;
  min_local=0;
  for (int i=0;i<n;i++) {
    if (px < sub.size() && sub[px] == i) {
      min_local += w[i];
      px++;
    } else {
      min_local -= w[i];
    }
  }

 min_all = min(min_all, abs(min_local));
}
void solve(ll i) {
  if (i == n) {
    test();
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

  cin >> n;
  for (int i=0;i<n;i++){
    int t;
    cin >> t;
    w.push_back(t);
  }
  solve(0);

  cout << min_all << endl;
}
