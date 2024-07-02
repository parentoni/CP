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
vector<pair<ll,bool>> indices;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i=0;i<n;i++){
    int a ,b;
    cin >> a >> b;
    indices.push_back({a, 1});
    indices.push_back({b, 0});
  }
  sort(all(indices));

  vector<int> customers(n*2+1);
  for (int i=1;i<=n*2;i++){
    if (indices[i-1].second) customers[i]++;
    else customers[i]--;
  }

  for (int i=1;i <=n*2;i++){
    customers[i]+= customers[i-1];
    y = max((ll)customers[i], y);
  }
  
  cout << y << endl;
}
