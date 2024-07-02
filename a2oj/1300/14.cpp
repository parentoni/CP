#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  int min = 101, max = 0;
  int minp = -1, maxp = 101;

  vector<int> a;
  int s=0;
  for (int i=0;i<n;i++){
    int h;
    cin >> h;
    if (h <= min) min = h;
    if (h >= max) max = h; 
    a.push_back(h);
  }

  for (int i=0;i<n;i++) {
    if (a[i] == min && i > minp) minp = i;
    if (a[i] == max && i < maxp) maxp = i;
  }

  if (maxp > minp) {
    s--;
  }

  s = s + maxp - 1 + n-minp;

  cout << s << endl;
}



