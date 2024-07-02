#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
//void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //setIO("");
  //freopen("", "r", stdin);
  int n;
  cin >> n;

  map<string,int> db;
  for (int i=0;i<n;i++){
    string name;
    cin >> name;
    if (!db[name]) {
      cout << "OK" << endl;
    } else {
      cout << name + to_string(db[name]) << endl;
      db[name + to_string(db[name])]= 1;
    }
    db[name]++;
  }
}

