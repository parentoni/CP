#include <bits/stdc++.h>
using namespace std;

#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n;
  cin >> n;

  int l = 0;

  while (n !=0) {
    if (n % 10 == 7 || n % 10 == 4) {
      l++;
    }

    n = n / 10;
  }

  if (l == 4 || l == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

