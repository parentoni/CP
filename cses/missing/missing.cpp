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

  //setIO("");
  //freopen("", "r", stdin);
  int n;
  cin >> n;

  vector<int> v(n-1);
  for (auto &el: v) cin >> el;


  
  sort(v.begin(),v.end());
  for (int i=0;i<n-1;i++){
    if (v[i] != i+1) {
      cout << i+1 << endl;
      return 0;
    }
  }

  cout << n << endl;
}

