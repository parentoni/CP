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

ll n,y=INF;
string r;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("whereami");
  
  cin >> n;
  cin >> r;

  for (ll i=1;i<=n;i++){
    set<string> sequences;
    bool valid = true;
    
    for (int j=0;j<=n-i;j++){
      string seq = "";
      for (int c=0;c<i;c++){
        seq += r[j + c];
      }
      if (sequences.count(seq) == 1) valid = false;
      sequences.insert(seq);
    }

    if (valid) y = min(y,i);
  }

  cout << y << endl;
}

