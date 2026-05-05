#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  double cnt[3][3] = {0};
  lin(i, 0, 3) {
    lin(j, 0, 6) {
      int num;
      cin >> num;

      if (num == 4)
        cnt[i][0]++;
      else if (num == 5)
        cnt[i][1]++;
      else if (num == 6)
        cnt[i][2]++;
    }
  }

  lin(i, 0, 3) {
    lin(j, 0, 3) { cnt[i][j] = (cnt[i][j] / 6.0); }
  }

  double ans = 0.0;
  ans = cnt[0][0] * (cnt[1][1] * cnt[2][2] + cnt[1][2] * cnt[2][1]) +
        cnt[0][1] * (cnt[1][0] * cnt[2][2] + cnt[1][2] * cnt[2][0]) +
        cnt[0][2] * (cnt[1][1] * cnt[2][0] + cnt[1][0] * cnt[2][1]);

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
