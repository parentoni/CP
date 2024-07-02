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


vector<ll> factors[100000 + 100];

void solve(){

  ll n,m, y=INF;
  cin >> n >> m;


  vl students(n, 0);
  vl frequency(m+1, 0);
  ll current = 0;

  for (auto &el: students) cin >> el;
  sort(all(students));

  
  int slow = 0;
  for (int i=0;i<n;i++){


    for (auto el: factors[students[i]]){
      if (el > m) break;
      if (!frequency[el]++) current++;
    }
    
    while (current == m) {
      y = min(y, students[i]-students[slow]);
    
      for (auto el: factors[students[slow]]){
        if (el > m) break;
        if (--frequency[el] == 0) current--;
      }
      slow++;
    }
  }

  if (y == INF) cout << -1 << endl;
  else cout << y << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i=1;i<=100000;i++){
    for (int j=i;j<=100000;j += i){
      factors[j].push_back(i);
    }
  }

  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
