#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> a(n);
  lin(i, 0, n) {
    int len;
    cin >> len;

    a[i].resize(len);

    // cout << "len:" << len << "\n";

    lin(j, 0, len) cin >> a[i][j];
  }

  int x, y;
  cin >> x >> y;

  cout << a[x - 1][y - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}
