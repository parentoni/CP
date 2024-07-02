#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  while (n--) {
    string w;
    cin >> w;
    if (w.size() > 10) {
      cout << w[0] << w.size() - 2 << w[w.size() - 1] << endl;;
    } else {
      cout << w << endl;
    }
  }
}

