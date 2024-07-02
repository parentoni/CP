#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int r = 0;
  while (n--) {
    char l, m,n;
    cin >> l >> m >> n;
    int c = 0;
    if (l == '1') c++;
    if (m == '1') c++;
    if (n == '1') c++;

    if (c >=2) r++;
  }
  cout << r << endl;
}

