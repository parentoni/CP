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
  ll n;
  cin >> n;

  while (n != 1) {
    
    cout << n << " ";
    if (n%2 == 0) n = n/ 2;
    else n = n*3 + 1;
  }
  cout << 1;
  cout << endl;
}

