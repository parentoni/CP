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
const ll mod = 1000000007;

ll n,q;
vl hol, guer, jers;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("bcount");
  cin >> n >> q;

  hol.resize(n+1);guer.resize(n+1);jers.resize(n+1);

  for (int i=1;i<=n;i++){
    int breed;
    cin >> breed;
    if (breed == 1) hol[i] = hol[i-1] + 1;
    else hol[i] = hol[i-1];

    if (breed == 2) guer[i] = guer[i-1] + 1;
    else guer[i] = guer[i-1];

    if (breed == 3) jers[i] = jers[i-1] + 1;
    else jers[i] = jers[i-1];
  }

  for (int i=0;i<q;i++) {
    int a,b;
    cin >> a >> b;
    cout << hol[b] - hol[a-1] << " " << guer[b] - guer[a-1] << " "<< jers[b] - jers[a-1] << endl;
  }
}
