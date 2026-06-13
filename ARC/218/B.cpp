#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  int mn = 2e9;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i], mn = max(mn, a[i]);

  if (mn & 1)
    cout << "Bob" << "\n";
  else
    cout << "Alice" << "\n";
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
