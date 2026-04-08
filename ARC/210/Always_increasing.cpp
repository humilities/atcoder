#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	//cout<<-1<<" ";

	vector<ll> c(n - 1);
	vector<ll> add(n);

	for (int i = 0; i < q; i++) {
		int j, x;
		cin >> j >> x;

		j--;
		add[j] += x;

		if (j < n - 1) {
			c[j] = max(c[j], add[j] - add[j + 1]);
		}
	}

	//cout<<endl;

	vector<ll> a(n);
	a[0] = 1;

	for (int i = 0; i < n-1; i++) {
		a[i + 1] = a[i] + c[i] + 1;
	}


	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}

	cout << ans << endl;

	return 0;
}