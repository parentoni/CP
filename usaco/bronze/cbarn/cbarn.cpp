#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("cbarn");
  freopen("cbarn.in", "r", stdin);
   
  int n, s = 0;
  cin >> n;
  vector<int> r;
  for (int i=0;i<n;i++){
    int t;
    cin >> t;
    r.push_back(t);
    s += t;
  }

  int q = INT_MAX;
  for (int i=0;i<n;i++) {
    int cows = s ;
    int ps = 0;
    for (int j=0; j<n;j++) {
      int in =(i + j) % n;
      if (cows > 0) {
        cows = max(cows - r[in], 0);
        ps += cows;
      }
    }
    q = min(ps, q);
  }

  cout << q << endl;
}
