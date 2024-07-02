#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;
const ll MAX_N = 10e5;

ll n;
ll parents[MAX_N] = -1;
vl tree[MAX_N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");
  
  cin >> n;
  for (int i=0;i<n-1;i++){
    ll a,b;
    cin >> a >> b;
    tree[b].push_back(a); tree[a].push_back(b)
  }

  
}
