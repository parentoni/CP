#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio();
  cin.tie();


  freopen("square.in", "r", stdin);
  int bl_x1, bl_y1, tr_x1, tr_y1;
  int bl_x2, bl_y2, tr_x2, tr_y2;
  
  cin >> bl_x1 >> bl_y1 >> tr_x1 >> tr_y1 >> bl_x2 >> bl_y2 >> tr_x2 >> tr_y2;

  int width = max(tr_x1,tr_x2) - min(bl_x1, bl_x2);
  int height = max(tr_y1,tr_y2) - min(bl_y1, bl_y2);

  freopen("square.out", "w", stdout);
  cout << max(width, height) * max(width, height) << endl;
}
