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

ll n, y = 0, total=0;
vector<pair<ll,pair<int, bool>>> indices;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("lifeguards");
  cin >> n;

  for (int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    indices.push_back({a,{i, 1}});
    indices.push_back({b,{i, 0}});
  }
  sort(all(indices));

  vector<ll> coverage(n*2+1);
  for (int i=1;i<=n*2;i++){
    if (indices[i-1].second.second) coverage[i]++;
    else coverage[i]--;
  }

  for (int i=1;i<=n*2;i++){
    coverage[i] += coverage[i-1];  
  }

  for (int i=0;i<n*2-1;i++){
    if (coverage[i+1] > 0) total +=  indices[i+1].first - indices[i].first;
  }

  vector<ll> alone(n);
  set<int> open;

  for (int i=0;i<n*2;i++){
    if (indices[i].second.second) open.insert(indices[i].second.first); 
    else open.erase(indices[i].second.first);

    if (open.size() == 1) {
      alone[*open.begin()] += indices[i+1].first - indices[i].first;
    }
  }

  for (auto el: alone) y = max(y, total-el);
  cout << y << endl;


}
