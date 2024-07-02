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
const ll MAX_N = 50000;


ll n, y =0;
bool taken[MAX_N * 2 + 1];
vl e, b, sorted_e;
map<ll, ll> e_pos;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("cardgame");
  cin >> n;
  
  for (int i=0;i<n;i++) {
    ll t; cin >> t;
    taken[t] = 1;
    e.push_back(t);
    sorted_e.push_back(t);

  }

  for (int i=1;i<=n*2;i++){
    if (!taken[i]) b.push_back(i);
  }
  sort(all(b)); sort(all(sorted_e));
  for (int i=0;i<n;i++){
    e_pos[sorted_e[i]] = i;
  }

  for (int i=0;i<n/2;i++){
    ll f = e[i]; 
    auto s = upper_bound(b.begin(), b.end(), e[i]); 

    cout << f << " " << *s << " " << (f < *s) << endl;
    if (f < *s) y++;
    b.erase(s);
  }

  for (int i=0;i<n/2;i++){
    cout << e[n/2+i] << " " << b[i] << " " << (e[n/2+i] > b[i]) << endl;
    if (e[n/2+i] > b[i]) y++;
  }


  cout << y << endl;
  

}
