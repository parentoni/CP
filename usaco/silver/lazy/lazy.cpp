#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

ll n, k;
int y = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("lazy");

  cin >> n >> k;
  int new_n = 2*n-1;

  vector<vector<int>> grass(new_n, vector<int>(new_n, 0));

  for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cin >> grass[i + j][n - i + j - 1]; }
	}

  vector<vector<int>> prefix(new_n+1, vector<int>(new_n+1,0));
  
  for (int i=0;i<new_n;i++){
    for (int j=0;j<new_n;j++){
      prefix[i+1][j+1] = grass[i][j] + prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
    }
  }

  for (int i=k;i<new_n-k;i++){
    for (int j=k;j<new_n-k;j++){
      y = max(y,
          prefix[i + k + 1][j + k + 1] - prefix[i + k + 1][j - k] -
          prefix[i - k][j + k + 1] + prefix[i - k][j - k]);
    }
  }

  if (k >= n) cout << prefix[new_n][new_n] << endl;
  else cout << y << endl;
}
