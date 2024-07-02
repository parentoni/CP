#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

void solve() {
  int k, q;
  cin >> k >> q;
  vector<int> a;
  vector<int> n;
  vector<int> results;

  for (int i=0;i<k;i++){
    int p;
    cin >> p;
    a.push_back(p);
  }

  for (int i=0;i<q;i++){
    int p;
    cin >> p;
    n.push_back(p);
  }

  
  for (int i=0;i<q;i++){
    int p = n[i];
    while (p>=a[0]) {
      for (auto el: a) {
        if (p>=el){
          p--;
        }
      }
    }

    results.push_back(p);
  }

  for (auto el: results) {
    cout << el << " ";
  }
  cout << endl;

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
