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

ll n, y = INF;
vector<ll> weights;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  weights.resize(n*2);

  for (auto &el: weights) cin >> el;
  sort(all(weights));

  for (int i=0;i<n*2;i++){
    for (int j=i+1;j<n*2;j++){
      vector<ll> wcp;
      ll local_sum = 0;

      for (int k=0;k<n*2;k++){
        if (k == i || k == j) continue;
        wcp.push_back(weights[k]);
      }

      for (int k=0;k<n*2-2;k+=2){
        local_sum += abs(wcp[k+1] - wcp[k]);
      }

      y = min(y, local_sum);
    }
  }

  cout << y << endl;
}
