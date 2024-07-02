#include <bits/stdc++.h>
using namespace std;

#define ll long long;
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string q;
  cin >> q;

  string r = "";
  for(int i = 0; i < q.size(); i++){
    if (q[i] == '.') {
      r += '0';
    } else {
      if (q[i + 1] == '.'){
        r += '1';
      } else {
        r += '2';
      }
      i++;
    }

  }

  cout << r << endl;
}
