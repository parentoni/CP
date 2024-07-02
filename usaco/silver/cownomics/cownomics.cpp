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
  int n, m;
  cin >> n >> m;


  vector<string> t(n*2);
  for (auto &el: t) cin >> el;

  ll s = 0;
  for (int a =0;a<m;a++){
    for (int b=a+1;b<m;b++){
      for (int c=b+1;c<m;c++) {

        set<string> sp;
        for (int r=0;r<n;r++) {
          string g="";
          g+= t[r][a]; g+= t[r][b]; g+= t[r][c];
          sp.insert(g);
        }

        bool dupe = false;
        for (int r=n;r<n*2;r++){
          string g="";
          g+= t[r][a]; g+= t[r][b]; g+= t[r][c];
          if (sp.count(g) == 1) {
            dupe = true;
            break;
          }
        }

        if (!dupe) s++;
      }
    }
  }

  cout << s << endl;
}

