#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  freopen("paint.in", "r", stdin);
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  int intersection = max(min(b,d) - max(a,c),0);
  freopen("paint.out", "w", stdout);
  cout << (b-a) + (d-c) - intersection << endl;
}
