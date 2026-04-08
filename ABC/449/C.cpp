#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, l, r;
  cin >> n >> l >> r;
  r++;

  string str;
  cin >> str;

  int cnt[26] = {0};
  long long ans = 0;

  for (int i = 0; i < n; i++) {
    if (i >= l)
      cnt[str[i - l] - 'a']--;
    if (i >= r)
      cnt[str[i - r] - 'a']++;

    ans += cnt[str[i] - 'a'];
  }

  cout << ans << endl;

  return 0;
}
