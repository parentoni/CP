#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

ll solve(vector<int> &a, int d) {
  ll s = 0;
  int max = 0;
  int dd = a[0] % d;
  for (int n=0;n<a.size();n++) {
    if (dd != a[n] % d) return -1;
  }
  sort(a.begin(), a.end());
  int med = a.size()/2;

  for (int n=0;n<a.size();n++){
    s = s + (abs(a[med] - a[n])) / d;
  }

  return s;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m, d;
  cin >> n >> m >> d;
  vector<int> a;
  for (int i=0;i<n;i++){
    vector<int> b;
    for (int i=0;i<m;i++){
      int e;
      cin >> e;
      a.push_back(e);
    }
  }

  cout <<solve(a,d) << endl;
}

