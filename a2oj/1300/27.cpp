#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s, c;
  cin >> s >> c;
  for(int i=0;i<s.size();i++){
    if (tolower(s[i]) != tolower(c[i])){
      if (tolower(s[i]) > tolower(c[i])) {
        cout << "1" << endl;
      } else {
        cout << "-1" << endl;
      }

      return 0;
    }
  }

  cout << "0" << endl;
}

