#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("shell");
  int n;
  cin >> n;
  int m[n][3];

  for (int i=0;i<n;i++){
    int a,b,g;
    cin >> a >> b >> g;
    m[i][0] = a;
    m[i][1] = b;
    m[i][2] = g;
  }

  int s =0;
  for (int i=0;i<3;i++){
    int p[3] = {0,0,0};
    p[i] = 1;
    int ps = 0;
    for (auto el: m) {
      swap(p[el[0] - 1], p[el[1] - 1]); 
      if (p[el[2] - 1] == 1){
        ps++;
      }
    }

    s = max(s, ps);
  }

  cout << s << endl;
}

