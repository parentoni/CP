#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  string n,m;
  cin >> n >> m;
 
  for (int i=0;i<n.size();i++){
    if (n[i] != m[i]) cout << "1";
    else cout << "0";
  }
  cout << endl;
}


