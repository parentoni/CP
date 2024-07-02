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

  vector<vl> charcount(26); 

  string x; 
  int q;
  cin >> x >> q;

  for (auto &count: charcount) count.resize(x.size()+1);
 
  for (int i=1;i<=x.size();i++) {
    for (auto &count: charcount) count[i] = count[i-1];
    charcount[(int)x[i-1]-97][i]++;
  }

  //for (auto count: charcount) {
  //  for (auto el: count) cout << el << " ";
  //  cout << endl;
  //}

  for (int i=0;i<q;i++){
    int a, b;
    cin >> a >> b;
    if (b == a) {cout << "Yes" << endl;continue;}

    map<ll,ll> count;

    for (int j=0;j<26;j++) {
      if (charcount[j][b] - charcount[j][a-1] > 0) count[j] = (charcount[j][b] - charcount[j][a -1]);
    }

    int keys = 0;
    for (auto el: count) keys++;

    if (keys >= 3 || x[a-1] != x[b-1]) cout << "Yes"<< endl;
    else cout << "No" << endl;
  }
}
