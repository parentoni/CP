#include <bits/stdc++.h>
using namespace std;

#define ll long long;
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,t;
  string q;
  cin >> n >> t >> q;

  while(t--) {
    for (int i = 0; i < n; i++) {
      if (q[i] == 'B' && q[i + 1] == 'G') {
        q[i] = 'G';
        q[i+1] = 'B';
        i++;
      }
    }
  }

  cout << q << endl;
}
