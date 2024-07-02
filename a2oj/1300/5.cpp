#include <bits/stdc++.h>
using namespace std;

#define ll long long;
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int y;
  cin >> y;

  while(y++) {
    int c = y;
    int f = 0;
    while (c != 0) {
      int d = c % 10;
      c = c/10;
      int cc = c;
      while (cc != 0) {
        if (cc % 10 == d) {
          f++;
        }
        cc = cc / 10;
      }
    }

    if (f == 0) {
      break;
    }
  }

  cout << y << endl;
}
