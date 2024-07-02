#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("lostcow");
  
  //freopen("lostcow.in", "r", stdin);
  int p, k;
  cin >> p >> k;
  
  int s = 0;
  int i = 1;
  int j = p;
  while (j != k) {
    if (int(log2(i)) % 2 == 0) {
      if (p + i > k && j < k) {
        s += k - j;
        j = k;
      } else {
        s += (i + p) - j;
        j = p + i;
      }
    } else {
      if (p - i < k && j > k) {
        s += j - k;
        j = k;
        //cout << (j - k) << endl;
      } else {
        s += j - (p - i);
        j = p - i;
      }
    }
    i *= 2;
  }

  cout << s << endl;
}
