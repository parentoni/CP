#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int area(int a, int b, int c, int d) {
  return max(c - a, 0) * max(d - b, 0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("billboard.in" , "r", stdin);
  int a1,b1,c1,d1;
  int a2,b2,c2,d2;
  int a3,b3,c3,d3;

  cin >> a1 >> b1 >> c1 >> d1;
  cin >> a2 >> b2 >> c2 >> d2;
  cin >> a3 >> b3 >> c3 >> d3;


  freopen("billboard.out", "w", stdout);
  int fi = max(min(c3,c1) - max(a3,a1),0) * max(min(d3,d1) - max(b3,b1), 0);
  int ti = max(min(c3,c2) - max(a3,a2),0) * max(min(d3,d2) - max(b3,b2), 0);

  cout << area(a1,b1,c1,d1) + area(a2,b2,c2,d2) - fi - ti << endl;
}
