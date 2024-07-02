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

// geometry
double DEG_to_RAD (double d) {return d*M_PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ M_PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const double EPS = 1e-9;


struct point{
  double x, y;
  point () {x=y=0;}
  double distance(const point &other) {
    return hypot(x-other.x, y-other.y);
  }

  void walk(string d,double t) {
    if (d == "N") {
      y += t;
    } else if (d == "S") {
      y -= t;
    } else if (d == "E") {
      x += t;
    } else if (d == "W") {
      x -= t;
    } else if (d == "NE") {
      double g = sqrt((t*t)/2.0);
      x += g; y+= g;
    } else if (d == "NW") {
      double g = sqrt((t*t)/2.0);
      x -= g; y += g;
    } else if (d == "SE") {
      double g = sqrt((t*t)/2.0);
      x += g; y-= g;
    } else{
      double g = sqrt((t*t)/2.0);
      x -= g; y-= g;
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(3);


  string line; ll c = 1;
  while(getline(cin, line)) {
    if (line == "END") break;
    point a,b;

    
    pair<string,string> v[1000];

    int i=0;
    for (int j=0;j<line.size()-1;j++) {
      char t = line[j];
      if (t>= '0' && t<= '9') {
        v[i].first +=t;
      } else if (t != ',') {
        v[i].second +=t;
      } else {
        i++;
      }

    }

    for (int j=0;j<=i;j++) {
      a.walk(v[j].second, (double) stoi(v[j].first));
    }

    cout << "Map #" << c << endl;
    cout << "The treasure is located at (" << a.x << "," << a.y << ")." << endl;
    cout << "The distance to the treasure is " << b.distance(a) << "." << endl;
    cout << endl;

    c++;

  }

}
