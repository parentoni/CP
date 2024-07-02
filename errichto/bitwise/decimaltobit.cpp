#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  unsigned long long n; cin >> n;

  for (int i=floor(log2(n));i>=0;i--) {
    if (n & (1ull << i)) cout << 1;
    else cout << 0;
  }

  cout << endl;
}
