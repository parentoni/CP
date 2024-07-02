#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<float> v(n);
  for (auto &el: v) cin >> el;

  int r =0;
  for (int i=0;i<n;i++){
    for (int j=i;j<n;j++){
      float s=0;
      for (int q=i;q<=j;q++) {
        s += v[q];
      }
     
      float avg = s/(j-i+1);
      for (int q=i;q<=j;q++) {
        if (v[q] == avg){r++;break;}
      }
    }
  }

  cout << r << endl;
}

