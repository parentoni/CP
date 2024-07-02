#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie();

  int n, k = 0, ans= 0;
  cin >> n;

  for (int i=0;i<n;i++){
    int q;
    cin >> q;
    k += q;
  }

  for (int i=1;i<=5;i++){
    if ((k+i) % (n + 1) != 1) {
      ans++;
    }
  }

  cout << ans << endl;
}
