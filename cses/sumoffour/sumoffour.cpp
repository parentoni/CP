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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, target;
  cin >> n >> target;

  vector<pair<ll,int>> values(n);

  for (int i=0;i<n;i++){
    ll t;
    cin >> t;
    values[i] = {t, i};
  }

  sort(all(values));

  
  
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      int left = 0;
      int right = n-1;

      int x = target - values[i].first - values[j].first;
      while(right != left){
        if (right != i && left != i && right != j && left != j 
          && values[right].first + values[left].first == x){
          cout << values[j].second +1<< " " << values[i].second + 1 <<" " << values[right].second + 1 << " " << values[left].second + 1 << endl;
          return 0;
        }

        if (values[right].first + values[left].first > x) {
          right--;
        } else {
          left++;
        }
      }
    }
  }

  cout << right << " " << left << endl;
  cout << "IMPOSSIBLE" << endl;
}

