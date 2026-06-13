#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod = 998244353;

ll power(ll base, ll exp) {
  ll res = 1;
  base %= mod;

  while (exp) {
    if (exp & 1)
      res = (res * base) % mod;
    base = (base * base) % mod;

    exp /= 2;
  }

  return res;
}

void solve() {
  int n, m;
  cin >> n >> m;

  map<int, vector<int>> ma;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int val;
      cin >> val;

      if (ma.find(val) == ma.end())
        ma[val].resize(n, 0);

      ma[val][i]++;
    }
  }

  ll tot = power(m, n);
  ll ans = 0;

  for (auto const &[val, cnt] : ma) {
    ll cho = 1;
    for (int i = 0; i < n; i++) {
      ll num = m - cnt[i];
      cho = (cho * num) % mod;
    }

    ll th = (tot - cho + mod) % mod;
    ans = (ans + th) % mod;
  }

  cout << ans << "\n";
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
