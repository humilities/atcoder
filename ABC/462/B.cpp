#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> gra(n + 1);
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;

    for (int j = 0; j < num; j++) {
      int u;
      cin >> u;

      gra[u].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    int size = gra[i].size();

    cout << size;
    for (int j = 0; j < size; j++)
      cout << " " << gra[i][j];
    cout << "\n";
  }
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
