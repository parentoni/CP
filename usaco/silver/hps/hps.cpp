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
vector<ll> rock, paper, scissor;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("hps");
  cin >> n;

  rock.resize(n+1); paper.resize(n+1); scissor.resize(n+1);

  for (int i=1;i<=n;i++){
    char p;
    cin >> p;
    if (p == 'H') paper[i] = paper[i-1]+1;
    else paper[i] = paper[i-1];

    if (p == 'P') scissor[i] = scissor[i-1]+1;
    else scissor[i] = scissor[i-1];

    if (p == 'S') rock[i] = rock[i-1]+1;
    else rock[i] = rock[i-1];
  }

  for (int i=1;i<=n;i++){
    ll before = max({rock[i], scissor[i], paper[i]});
    ll after = max({rock[n] - rock[i], scissor[n] - scissor[i], paper[n] - paper[i]});

    y = max(y, after+before);
  }

  cout << y << endl;
}
