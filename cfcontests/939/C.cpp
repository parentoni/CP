#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

void solve() {
  int n;
  cin >> n;

  int m[n][n] = {0};
  
  vector<int> t;
  vector<int> p;
  vector<vector<int>> o;

  vector<int> per; 
  for (int i=0;i<n;i++) {
    per.push_back(i + 1);
  }

  for (int r=0;r<n;r++){
    for (int c=0;c<n;c++) {
      m[r][c] = c+ 1;
    }
    t.push_back(1);
    p.push_back(r + 1);
    o.push_back(per);
  }
  
  for (int c=0;c<n-1;c++){
    for (int r=0;r<n;r++){
      m[r][c] = r+1;
    }

    t.push_back(2);
    p.push_back(c + 1);
    o.push_back(per);
  }

  if (n>2) {
    for (int c=0;c<n;c++) m[0][c] = c+1;

    t.push_back(1);
    p.push_back(1);
    o.push_back(per);
  }

  
  ll sum = 0;
  for (int r=0;r<n;r++) {
    for (int c=0;c<n;c++) {
      sum += m[r][c];
    }
  }


  cout << sum << " " << t.size() << endl;
  for (int i=0;i<t.size();i++){
    cout << t[i] << " " << p[i] << " ";
    for (auto el: o[i]) {
      cout << el << " ";
    }
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

