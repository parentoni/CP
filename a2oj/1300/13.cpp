#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int i;
  cin >> i; 
  if (i % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }

  for (int c = 0;c<i/2;c++){
    cout << (2 + c * 2) << " " << (1 + c * 2) << " "; 
  }

  cout << endl;
}


