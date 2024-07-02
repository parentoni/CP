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

ll n;
map<string,string> v;
void ops(int m, string i, string value_to_be_set){
  if (m == 0) {
    v[i] = value_to_be_set;
  } else {
    if (v[i] == "") cout << "0" << endl;
    else cout << v[i] << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i=0;i<n;i++){
    int m;
    string k,val = "";
    cin >> m >> k;
    if (m == 0) cin >> val;
    ops(m,k,val);
  }
}

