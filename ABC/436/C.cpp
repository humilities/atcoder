#include <bits/stdc++.h>
using namespace std;

struct HashPair {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    unordered_set<pair<int, int>, HashPair> occupied;
    int count = 0;
    
    for (int i = 0; i < M; ++i) {
        int R, C;
        cin >> R >> C;
        
        if (R + 1 > N || C + 1 > N) {
            continue;
        }
        
        if (occupied.count({R, C})) {
            continue;
        }
        
        bool overlap = false;
        
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) continue;
                
                int r = R + dr;
                int c = C + dc;
                
                if (r < 1 || r > N-1 || c < 1 || c > N-1) {
                    continue;
                }
                
                if (occupied.count({r, c})) {
                    overlap = true;
                    break;
                }
            }
            if (overlap) break;
        }
        
        if (!overlap) {
            occupied.insert({R, C});
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}