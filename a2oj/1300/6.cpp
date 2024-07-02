#include <bits/stdc++.h>
using namespace std;

#define ll long long;
#define ar array;

int flip(int a) {
  if (a == 1) {
    return 0;
  }

  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> a(9,1);

  int l;
  for (int i = 0; i < 9; i++){
    cin >> l;
    if (l% 2 !=0){
      a[i] = flip(a[i]);

      if (i + 1 < 9) {
        if ((i + 1) % 3 != 0) {
          a[i + 1] = flip(a[i + 1]);
        }
      }
      if (i - 1 >= 0) {
        if (i % 3 != 0) {
          a[i - 1] = flip(a[i - 1]);
       }
      }
      if (i + 3 < 9) {
        a[i + 3] = flip(a[i + 3]);
      }
      if (i - 3 >= 0) {
        a[i - 3] = flip(a[i - 3]);
      }
    }
  }

  for (int i = 0; i < 9; i++){
    cout << a[i];
    if ((i+ 1) % 3 == 0 && i != 0){
      cout <<endl;
    }
  }
}

