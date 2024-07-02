#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string w;
  cin >> n >> w;
  if (n < 26) {
    cout << "NO"<< endl;
    return 0;
  }
  map<char, int> m;

  for (int i=97;i< 97 + 26;i++){
    m[char(i)] = 0;
  }

  for (auto el: w){
    m[tolower(el)]++;
  }

  for (int i=97;i<97 + 26;i++){
    if (m[char(i)] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
}

