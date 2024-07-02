#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int s=0;
  int q=0; 
  for (int i=0;i<n*2;i++){
    int p;
    cin >> p;
    if (i % 2 == 0){
      q = q - p;
    } else {
      q = q + p;
    }

    s = max(s, q);
  }


  cout << s << endl;
}

