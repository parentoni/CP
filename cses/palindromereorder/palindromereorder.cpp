#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string x;
  cin >> x;
  map<char,int> letters;

  for (auto el: x) letters[el]++;
  
  char odd = '0';
  for (auto el: letters){
    if (el.second % 2 == 1 && x.size() % 2 == 0) {
      cout << "NO SOLUTION" << endl;
      return 0;
    } else if (x.size() % 2 == 1 && el.second % 2 == 1) {
      if (odd != '0') {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
      odd = el.first;
    }
  }

  for (int i=0;i<26;i++) {
    for (int j=0;j<letters[(char)('A' + i)]/2;j++){
      cout << (char)('A' + i);
    }
  }
  if (odd != '0') cout << odd;

  for (int i=25;i>=0;i--){
    for (int j=0;j<letters[(char)('A' + i)]/2;j++){
      cout << (char)('A' + i);
    }
  }
  cout << endl;
}
