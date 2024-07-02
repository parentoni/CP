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
  vector<int> c;
  for (int i=0;i<n;i++){
    int p;
    cin >> p;
    c.push_back(p);
  }

  sort(c.begin(), c.end());
  int r = 0;
  for (int i=0;i<n-1;i++){
    if(c[i] == c[i + 1]) r++;
  }
  cout << r << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while(t--) {
    solve();
  }

}

