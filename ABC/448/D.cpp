#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mn = 200005;
vector<int> adj[mn];
ll a[mn];
int dupl = 0;
int cnt[mn];
string ans[mn];

void dfs(int u, int p) {
  if (cnt[a[u]] == 1)
    dupl++;
  cnt[a[u]]++;

  if (dupl > 0)
    ans[u] = "Yes";
  else
    ans[u] = "No";

  for (int v : adj[u])
    if (v != p)
      dfs(v, u);

  cnt[a[u]]--;
  if (cnt[a[u]] == 1)
    dupl--;
}

void solve() {
  int n;
  cin >> n;

  vector<int> val;
  for (int i = 1; i <= n; i++)
    cin >> a[i], val.push_back(a[i]);

  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());

  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, -1);

  for (int i = 1; i <= n; i++)
    cout << ans[i] << "\n "[i == n];
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
