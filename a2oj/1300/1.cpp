#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x,y,z;
  x = y = z = 0;

  int t;
  cin >> t;
  while(t--){
    //code
    int xi, yi, zi;
    cin >> xi >> yi >> zi;
    x = x + xi;
    y = y + yi;
    z = z + zi;
  }

  if (x == 0 && y == 0 && z == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

