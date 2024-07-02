#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int x = 0;

  while(n--){
    string s;
    cin >> s;
    for (auto el: s) {
      if (el == '-') {
         x--;
        break;
      }
      if (el == '+') {
         x++;
          break;
      }
    }}

  cout << x << endl;
}

