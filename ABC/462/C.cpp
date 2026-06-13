#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
  int x;
  int y;
};

bool comparen(const node &a, const node &b) { return a.x < b.x; }

void solve() {
  int n;
  cin >> n;

  vector<node> gra(n);
  for (int i = 0; i < n; i++) {
    cin >> gra[i].x >> gra[i].y;
  }

  sort(gra.begin(), gra.end(), comparen);

  int ans = 0;
  int mi = 1e9;

  for (int i = 0; i < n; i++) {
    if (gra[i].y < mi)
      ans++;

    mi = min(mi, gra[i].y);
  }

  cout << ans;
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
