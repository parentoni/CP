#include <bits/stdc++.h>
using namespace std;

#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  int r = 0;
  for (int i=0;i<n;i++){
    if (s[i] == s[i + 1]) {
       r++;
      }
  }

  cout << r << endl;
}

