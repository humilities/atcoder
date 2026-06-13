#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll a, b, x, y;
  cin >> a >> b >> x >> y;

  x = llabs(x);
  y = llabs(y);

  if (a > b) {
    swap(a, b);
    swap(x, y);
  }

  ll mi = min(x, y);
  ll mn = max(x, y);
  ll dif = mn - mi;

  auto get = [a, b, x, y](ll i, ll j) -> ll {
    if (i % 2 == 0) {
      ll line = i / 2 - j;
      return j * 2 * a + line * (a + b);
    } else {
      ll rem = (x >= y) ? a : b;
      ll lind = (i - 1) / 2 - j;

      return rem + j * 2 * a + lind * (a + b);
    }
  };

  ll ans = 0;

  if (b >= 3 * a && dif > 0) {
    ll c = dif / 2;

    ans = get(x + y + 2 * c, mi + 2 * c);
  } else
    ans = get(x + y, mi);

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
