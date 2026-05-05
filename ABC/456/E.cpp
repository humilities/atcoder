#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int w;
  cin >> w;

  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];

  int tol = n * w;
  vector<vector<int>> sta(tol);
  vector<int> in(tol, 0);
  vector<int> is(tol, false);

  lin(i, 0, n) { lin(j, 0, w) if (s[i][j] == 'o') is[i * w + j] = true; }

  lin(i, 0, n) {
    lin(j, 0, w) {
      int idx = i * w + j;

      if (!is[idx])
        continue;

      int nexd = (j + 1) % w;
      int stay = i * w + nexd;

      if (is[stay]) {
        sta[idx].push_back(stay);
        in[stay]++;
      }

      for (int v : adj[i]) {
        int move = v * w + nexd;

        if (is[move]) {
          sta[idx].push_back(move);
          in[move]++;
        }
      }
    }
  }

  queue<int> q;
  for (int i = 0; i < tol; i++)
    if (is[i] && in[i] == 0)
      q.push(i);

  vector<bool> rem(tol, false);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    rem[cur] = true;
    for (int j : sta[cur]) {
      in[j]--;

      if (in[j] == 0)
        q.push(j);
    }
  }

  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (is[i * w] && !rem[i * w]) {
      flag = true;
      break;
    }
  }

  if (flag)
    cout << "Yes" << "\n";
  else
    cout << "No" << "\n";
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
