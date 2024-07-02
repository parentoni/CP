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
  setIO("cowsignal");

  int n, m, k;
  cin >> n >> m >> k;

  vector<string> s;
  for (int i=0;i<n;i++){
    string l;
    cin >> l;
    s.push_back(l);
  }

  string b;
  for (int r=0;r<n*k;r++){
    for (int c=0;c<n*k;c++){
      b += s[r / k][c/k];
    }
    b+= "\n";
  }

  cout << b << endl;
}
