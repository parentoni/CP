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

ll n, y=0;
vector<pair<int,int>> mountains;
 
bool cmp (pair<int,int> a, pair<int,int> b){
  if (a.first == b.first) {return a.second > b.second;}
  return a.first < b.first;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("mountains");
  cin >> n;

  mountains.resize(n);
  for (auto &el: mountains) {
    int a,b;
    cin >> a >> b;
    mountains.push_back({a-b, a+b});
  }

  sort(all(mountains), cmp);

  // see open mountains
  int rightmost = -1;
  for (auto el: mountains){
    if(el.second > rightmost) {
      rightmost = el.second;
      y++;
    }
  }

  cout << y << endl;
}
