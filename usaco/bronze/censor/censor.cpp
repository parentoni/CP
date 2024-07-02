#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define all(x) (x).begin(), (x).end()

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll mod = 1000000007;

string s, t=" ";
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("censor");
  //freopen("censor.in", "r", stdin);
  cin >> s >> t;

  string censored;
  for (int i=0;i<s.size();i++){
    censored+=s[i];
    if (censored.size() > t.size() && censored.substr(censored.size() - t.size(), t.size()) == t){
      censored.resize(censored.size() - t.size());
    }
  }
  cout << censored << endl;
}

