#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mn = 1e6 + 1;

void solve() {
  int n, d;
  cin >> n >> d;

  vector<int> dx(mn, 0);

  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;

    t -= d;

    if (s <= t)
      dx[s]++, dx[t + 1]--;
  }

  ll ans = 0;
  int cur = 0;

  for (int i = 1; i <= mn; i++) {
    cur += dx[i];

    if (cur >= 2)
      ans += (ll)cur * (cur - 1) / 2;
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
