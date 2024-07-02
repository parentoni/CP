#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
//void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> e;
  vector<int> o;

  int n;
  cin >> n;

  for (int i=0;i<n;i++) {
    int t;
    cin >> t;
    if (t%2 == 0) e.push_back(i);
    else o.push_back(i);
  }

  if (e.size() < o.size()) cout << e[0] + 1 << endl;
  else cout << o[0]+1<< endl;
}

