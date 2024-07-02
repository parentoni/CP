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

ll n;
vector<pair<int,pll>> cows[4]; // directions
bool stopped[1000]; pair<int,pll> stop_loc[1000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


ll intersect(pair<int,pll> cowa, pair<int,pll> cowb, int da, int db) {
  ll inter = inf;

  if (dx[da]

  return inter;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n;
  for (int i=0;i<n;i++){
    char d; int x,y;
    cin >> d >> x >> y;
    if (d == 'E') cows[0].push_back({i, {x,y}});
    if (d == 'W') cows[1].push_back({i, {x,y}});
    if (d == 'N') cows[2].push_back({i, {x,y}});
    if (d == 'S') cows[3].push_back({i, {x,y}});
  }

  sort(all(cows[0]), [](pair<int,pll> &a, pair<int,pll> &b){
    return a.second.first > b.second.first;
  });

  sort(all(cows[1]), [](pair<int,pll> &a, pair<int,pll> &b){
    return a.second.first < b.second.first;
  });

  sort(all(cows[2]), [](pair<int,pll> &a, pair<int,pll> &b){
    return a.second.second > b.second.second;
  });

  sort(all(cows[3]), [](pair<int,pll> &a, pair<int,pll> &b){
    return a.second.second < b.second.second;
  });


  for (int d=0;d<4;d++){
    for (auto cow: cows[d]){
      for (int d2=0;d2<4;d2++){
        if (d2 == d) continue;
        for (auto cowb: cows[d2]){
          ll inter = intersect(cow, cowb, d, d2);
        }
      }
    }
  }
}
