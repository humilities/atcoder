// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <climits>

// using namespace std;
// using ll = long long; // 用long long避免32位整数溢出

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr); // 加速输入输出

//     int N_original;
//     cin >> N_original;
//     int N = N_original + 2; // 对应Python的N = int(input()) + 2

//     string S_original;
//     cin >> S_original;
//     string S = "#" + S_original + "#"; // 两端加#（模拟有树区间）

//     vector<int> R_original(N_original);
//     for (int i = 0; i < N_original; ++i) {
//         cin >> R_original[i];
//     }
//     // 构造R数组：[0] + 原始R + [0]
//     vector<int> R(N, 0);
//     for (int i = 0; i < N_original; ++i) {
//         R[i + 1] = R_original[i];
//     }

//     // 游程编码（RLE）：统计连续相同状态（有树/无树）下的R最大值和计数
//     char now = '#';
//     int mx = 0;
//     int cnt = 0;
//     vector<pair<int, int>> rle; // 存储(当前区间R最大值, 该最大值出现次数)

//     for (int i = 0; i < N; ++i) {
//         if (S[i] == now) {
//             // 当前字符与上一个相同，更新最大值和计数
//             if (R[i] == mx) {
//                 cnt++;
//             } else if (R[i] > mx) {
//                 mx = R[i];
//                 cnt = 1;
//             }
//         } else {
//             // 状态切换，保存当前区间的统计结果
//             rle.emplace_back(mx, cnt);
//             now = S[i];
//             mx = R[i];
//             cnt = 1;
//         }
//     }
//     // 移除第一个冗余元素（对应Python的rle = rle[1:]）
//     if (!rle.empty()) {
//         rle.erase(rle.begin());
//     }

//     // 找到所有区间中的R最大值
//     int global_mx = 0;
//     for (auto& p : rle) {
//         global_mx = max(global_mx, p.first);
//     }

//     // 计算答案：遍历奇数位置（步长2），判断三连区间最大值是否等于全局最大值
//     ll ans = 0;
//     for (int i = 0; i + 2 < rle.size(); i += 2) {
//         int curr_max = max({rle[i].first, rle[i+1].first, rle[i+2].first});
//         if (curr_max == global_mx) {
//             ans += (ll)rle[i].second * rle[i+2].second;
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }




#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int N=n+2;

	string str;
	cin >> str;
	str = "#" + str + "#";

	vector<int> r_o(n);
	for (int i = 0; i < n; i++) {
		cin >> r_o[i];
	}

	vector<int> r(N, 0);
	for (int i = 0; i < n; i++) {
		r[i + 1] = r_o[i];
	}

	vector<pair<int, int>> rle;

	char now = '#';
	int mx = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == now) {
			if (r[i] == mx) {
				cnt++;
			}
			else if(r[i] > mx) {
				mx = r[i];
				cnt = 1;
			}
		}

		else {
			rle.emplace_back(mx, cnt);
			now = str[i];
			cnt = 1;
			mx = r[i];
		}
	}

	if (!rle.empty()) {
		rle.erase(rle.begin());
	}

	int globe = 0;
	for (auto& p : rle) {
		globe = max(globe, p.first);
	}

	ll ans = 0;
	for (int i = 0; i + 2 < rle.size(); i += 2) {
		int cur = max({rle[i].first, rle[i + 1].first, rle[i + 2].first});

		if (cur == globe) {
			ans += (ll)rle[i].second * rle[i + 2].second;
		}
	}

	cout << ans << endl;

	return 0;
}

