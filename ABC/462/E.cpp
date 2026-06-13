#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128_t;

const i128 INF = (i128)4e18;

void solve() {
  ll a, b, x, y;
  cin >> a >> b >> x >> y;

  x = llabs(x);
  y = llabs(y);

  auto getEvenCost = [a, b](ll nx, ll ny) -> ll {
    nx = llabs(nx);
    ny = llabs(ny);
    if (nx < ny)
      swap(nx, ny);

    ll c = min(a, b);
    i128 diag = 2LL * c;
    i128 str = min(a + b, 4LL * c);

    i128 cost = diag * ny + str * ((nx - ny) / 2);
    return (ll)cost;
  };

  ll ans = 0;

  if (x % 2 == y % 2)
    ans = getEvenCost(x, y);
  else {
    i128 best = INF;

    best = min(best, (i128)getEvenCost(x + 1, y) + a);
    if (x > 0)
      best = min(best, (i128)getEvenCost(x - 1, y) + a);

    best = min(best, (i128)getEvenCost(x, y + 1) + b);
    if (y > 0)
      best = min(best, (i128)getEvenCost(x, y - 1) + b);

    ans = (ll)best;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
