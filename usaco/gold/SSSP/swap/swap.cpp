#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// geometry
const double PI = 3.14159265358979323846;
double DEG_to_RAD (double d) {return d*PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

unordered_set<string> visited;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

string target = "123456789";
pair<string,int> a;

int index(int y, int x) {
  return y * 3 + x;
}
queue<pair<string, int>> q;
/**
 * t the current board.
 * a the position to swap
 * b the destination
 * */
void swapt(pair<int,int> x, pair<int,int> y) {
  swap(a.first[index(x.first, x.second)], a.first[index(y.first, y.second)]);
  if (visited.find(a.first) == visited.end()) {
    visited.insert(a.first);
    q.push({a.first, a.second+1});
  }
  swap(a.first[index(y.first, y.second)], a.first[index(x.first, x.second)]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string initial = "";
  for (int i=8;i>=0;i--) {
    char t; cin >> t;
    initial += t; 
  }

  visited.insert(initial);
  q.push({initial, 0});
  
  while(q.size()){
    a = q.front();
    if (a.first == target) {
      cout << a.second << endl;
      return 0;
    };

    for (int i=0;i<3;i++) {
      for (int j=0;j<=1;j++) {
        swapt({i, j}, {i, 1+j});
      }
    }

    for (int i=0;i<3;i++) {
      for (int j=0;j<=1;j++) {
        swapt({j, i}, {j+1, i});
      }
    }


    q.pop();
  }

}
