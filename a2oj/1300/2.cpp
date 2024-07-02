#include <bits/stdc++.h>
using namespace std;

#define ll long long;
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int r = 0; r < 5;r++) {
    for (int c = 0; c < 5;c++) {
      int v;
      cin >>v;

      if (v == 1) {
        cout << abs(r - 2) + abs(c - 2)<< endl;
      }
    }
  }
}
