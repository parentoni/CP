#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s;
  cin >> s;

  int r = 0;
  vector<int> v;
  for (int i=0;i<s.size();i++) {
    if (s[i] != '+') {
      string c;
      c.push_back(s[i]);
      v.push_back(stoi(c));
    }
  }
  
  sort(v.begin(), v.end());
  for (int i =0;i<v.size();i++){
    cout << v[i]; 
    if (i != v.size() - 1) {
      cout << "+";
    }
  }
  cout << endl;
}

