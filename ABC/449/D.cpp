#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int l, r, d, u;
  cin >> l >> r >> d >> u;
  ll ans = 0;

  for (int x = l; x <= r; x++) {
    if (x % 2 == 0) {
      int D = max(d, -abs(x) + 1);
      int U = min(u, abs(x) - 1);
      int C = U - D + 1;
      ans += max(C, 0);
    }
  }

  for (int y = d; y <= u; y++) {
    if (y % 2 == 0) {
      int L = max(l, -abs(y));
      int R = min(r, abs(y));
      int C = R - L + 1;
      ans += max(C, 0);
    }
  }

  cout << ans << '\n';
}
