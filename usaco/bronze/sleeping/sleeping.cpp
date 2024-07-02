#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int ops(int total, int t, vector<int> v) {
  int ops =0;
  vector<int> vc = v;
  int sum =0;
  for (int i=0;i<v.size();i++){
    sum+= v[i];
    if (sum > t) {
      return INT_MAX;
    }

    if (sum == t) {
      sum = 0;
    }
  }
  return v.size() - total/t;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  int s = 0;
  for (int i=0;i<n;i++) {
    int t;
    cin >> t;
    s+= t;
    v.push_back(t);
  }


  bool equal = true;
  for (int i=0;i<n-1;i++) if (v[i] != v[i+1]) equal =false;
  if (equal) {
    cout << 0 << endl;
  } else {
    int r = INT_MAX;
    for (int i=1;i<=s;i++){
      if (s%i == 0) {
        r = min(r, ops(s, i, v));
      }
    }
    cout << r << endl;
  }
   


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--){
    solve();
  }
}

