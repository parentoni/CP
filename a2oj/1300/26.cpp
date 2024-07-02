#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  getline(cin, line);
  for (auto el: line) {
    if (el == 'H' || el == 'Q' || el == '9'){
      cout << "YES" << endl;
      return 0;
  }
  }
  cout << "NO" << endl;
}

