#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("cownomics");
  //freopen("cownomics.in", "r", stdin);
  int n,m;
  cin >> n >> m;
  char g[n*2][m] = {0};
  for (int i=0;i<n*2;i++) {
    string l;
    cin >> l;
    for (int j=0;j<m;j++){
      g[i][j] = l[j];
    }
  }

  int r =0;
  for (int c=0;c<m;c++) {
    set<char>s;
    set<char>p;

    for (int r=0;r<n;r++) {s.insert(g[r][c]);}
    for (int r=n;r<n*2;r++) {p.insert(g[r][c]);}
   
    int f=0;
    for (auto el: s) {
      for (auto elb: p) {
        //cout << el << " " << elb << endl;
        if (el == elb)f++;
      }


    }
    if (f==0) r++;

  }

  cout << r << endl;

}

