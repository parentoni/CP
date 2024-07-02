#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pii = pair<int,int>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

ll m, n, y=0;
vector<pair<ll,bool>> positions;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  positions.resize(m + n);
  vl distance(n+m,-1);

  for (int i=0;i<n;i++){
    int t;
    cin >> t;
    positions[i] = {t,0};
  }

  for (int i=n;i<n+m;i++){
    int t;
    cin >> t;
    positions[i] = {t,1};
  }
  sort(all(positions));


  for (int i=0;i<n+m;i++){
    if (positions[i].second){
      //cout << positions[i].first << " " << i<< endl;
      int left = i-1, right = i+1;
      while (left >= 0) {
        if (positions[left].second) break;
        if (distance[left] == -1) distance[left] = abs(positions[i].first - positions[left].first);
        else distance[left] = min(distance[left], abs(positions[i].first - positions[left].first));
        left--;
      }

      while (right < m+n){
        if (positions[right].second) break;
        //cout << right << " " << positions[right].first << endl;
        if (distance[right] == -1) distance[right] = abs(positions[right].first - positions[i].first);
        else distance[right] = min(distance[right], abs(positions[right].first - positions[i].first));
        right++;
      }
    }
  }

  for (auto el: distance) y = max(y,el);

  cout << y << endl;
}
