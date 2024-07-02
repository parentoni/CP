#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;

ll n, swaps=0;
vector<ll>a;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  a.resize(n);

  for (auto &el: a) cin >> el;

  for (int i=0;i<n;i++) {
    for (int j=0;j<n-1;j++) {
      if (a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
        swaps++;
      }
    }
  }
  cout << "Array is sorted in " << swaps << " swaps."<<endl;
  cout << "First Element: " << a[0] << endl;
  cout << "Last Element: " << a[n-1] << endl;
}

