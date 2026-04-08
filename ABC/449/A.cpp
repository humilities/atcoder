#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double q;
  cin >> q;

  q /= 2.0;

  double pi = acos(-1.0);

  cout << fixed << setprecision(15) << pi * q * q << endl;
  return 0;
}
