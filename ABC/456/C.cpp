#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod = 998244353;

ll get(ll x) { return ((x * (x + 1)) / 2) % mod; }

void solve() {
  string s;
  cin >> s;

  int len = s.length();
  ll ans = 0;

  ll i = 0;
  while (i < len) {
    ll j = i;
    while (j + 1 < len && s[j] != s[j + 1])
      j++;

    ll len1 = j - i + 1;
    ans = (ans + get(len1)) % mod;

    i = j + 1;
  }

  cout << ans << "\n";
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
