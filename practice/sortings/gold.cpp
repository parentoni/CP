#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int solve() {
  int n;
  cin >> n;

  vector<vector<int>> v;
  for (int i=0;i<n;i++){
    vector<int> a;
    for (int c=0;c<5;c++){
      int p;
      cin >> p;
      a.push_back(p);
    }
    sort(a.begin(), a.end());
    v.push_back(a);
  }

  int min[5]= {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
  int atl[5] = {-1,-1,-1,-1,-1};
  int e = 0;
  for (int i=0;i<n;i++){
    for (int c=0;c<5;c++){
      if (v[i][c] < min[c]) {
        min[c] = v[i][c];
        atl[c] = i;
      }
    }
  }

  map<int, int> c;
  for (auto el: atl) {
    c[el]++;
  }
  for (auto el: c){
    //cout << "el " << el.second << endl;
    if (el.second >= 3){
      cout << el.first + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
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

