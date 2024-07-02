#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll MOD = 1000000007;

struct Movie {
  ll start,end,duration;
};

ll n, y =0;
vector<Movie> festival;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n;

  for (int i=0;i<n;i++){
    ll a, b;
    cin >> a >> b;
    festival.push_back({a, b, b-a});
  }

  sort(all(festival), [](Movie &a, Movie &b) {
    return a.end < b.end;
  });


  ll local_max = 0;
  for (auto el: festival){
    if (el.start >= local_max) {
      y++;
      local_max = el.end;
    }
  }

  cout << y << endl;
}
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll MOD = 1000000007;

struct Movie {
  ll start,end,duration;
};

ll n, y =0;
vector<Movie> festival;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n;

  for (int i=0;i<n;i++){
    ll a, b;
    cin >> a >> b;
    festival.push_back({a, b, b-a});
  }

  sort(all(festival), [](Movie &a, Movie &b) {
    return a.end < b.end;
  });


  ll local_max = 0;
  for (auto el: festival){
    if (el.start >= local_max) {
      y++;
      local_max = el.end;
    }
  }

  cout << y << endl;
}
