#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

long long solve() {
    vector<long long> A(10); 
    long long total_sum = 0;
    
    for (int i = 1; i <= 9; ++i) {
        if (!(cin >> A[i])) return -1;
        total_sum += A[i];
    }
    
    if (2 * A[5] > total_sum + 1) {

        return 2 * A[5] - total_sum - 1;
    }

    int unique_count = 0;
    for (int i = 1; i <= 9; ++i) {
        if (A[i] > 0) {
            unique_count++;
        }
    }

    if (unique_count == 2) {
        int c1 = -1, c2 = -1;

        for (int i = 1; i <= 9; ++i) {
            if (A[i] > 0) {
                if (c1 == -1) c1 = i;
                else c2 = i;
            }
        }

        if (c1 + c2 == 10) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    
    while (T--) {
        cout << solve() << "\n";
    }

    return 0;
}