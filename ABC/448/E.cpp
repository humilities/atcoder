#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

ll mod;

ll po(ll a, ll b) {
  ll res = 1, cur = a;

  while (b) {
    if (b & 1LL)
      res *= cur, res %= mod;

    cur *= cur, cur %= mod;
    b >>= 1LL;
  }

  return res;
}

void solve() {
  int k, m;
  cin >> k >> m;

  mod = m * 10007;

  vector<ll> c(k), l(k);
  for (ll i = 0; i < k; i++)
    cin >> c[i] >> l[i];

  vector<ll> por(30);
  por[0] = 10;
  for (ll i = 1; i < 30; i++)
    por[i] = (por[i - 1] * por[i - 1]) % mod;

  vector<ll> rpo(30);
  rpo[0] = 1;
  for (ll i = 1; i < 30; i++)
    rpo[i] = (rpo[i - 1] * por[i - 1] + rpo[i - 1]) % mod;

  ll res = 0;
  ll dgt = 0;

  for (ll i = k - 1; i >= 0; i--) {
    ll ce = (c[i] * po(10, dgt)) % mod;
    ll r = 0;

    for (int j = 29; j >= 0; j--) {
      if (l[i] & (1LL << j))
        r = (r * por[j] + rpo[j]) % mod;
    }

    res += ce * r;
    res %= mod;

    dgt += l[i];
  }

  cout << res / m << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
