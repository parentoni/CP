
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  double n;
  cin >> n;

  double s=0;
  for (int i=0;i<n;i++){
    int v;
    cin >> v;
    s = s + v/100.0;
  }

  cout << s/n * 100 << endl; 
}

