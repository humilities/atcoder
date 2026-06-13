#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<vector<int>> a(n);
  vector<int> len(n);
  lin(i, 0, n) {
    cin >> len[i];

    a[i].resize(len[i]);

    lin(j, 0, len[i]) cin >> a[i][j];
  }

  vector<ll> c(n);
  lin(i, 0, n) cin >> c[i];

  int idx = -1;
  lin(i, 0, n) {
    ll tot = c[i] * len[i];
    if (k <= tot) {
      idx = i;
      break;
    } else
      k -= tot;
  }

  k -= 1;
  ll fin = k % len[idx];

  cout << a[idx][fin] << "\n";
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
