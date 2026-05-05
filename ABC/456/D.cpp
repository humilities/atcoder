#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod = 998244353;

void solve() {
  string s;
  cin >> s;

  ll dp[3] = {0, 0, 0};
  ll ans = 0;

  for (char c : s) {
    int i = c - 'a';

    ll cnt = 0;
    for (int j = 0; j < 3; j++)
      if (j != i)
        cnt = (cnt + dp[j]) % mod;

    dp[i] = (dp[i] + cnt + 1) % mod;
  }

  ans = (dp[0] + dp[1] + dp[2]) % mod;

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
