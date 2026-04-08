#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W;
    cin >> H >> W;
    vector<string> maze(H);
    for (int i = 0; i < H; ++i) {
        cin >> maze[i];
    }
    
    unordered_map<char, vector<pair<int, int>>> warp_map;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c = maze[i][j];
            if (islower(c)) {
                warp_map[c].emplace_back(i, j);
            }
        }
    }
    
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> q;
    
    dist[0][0] = 0;
    q.emplace(0, 0);
    
    unordered_set<char> warp_used;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == H-1 && y == W-1) {
            cout << dist[x][y] << endl;
            return 0;
        }
        
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (maze[nx][ny] != '#' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
        
        char c = maze[x][y];
        if (islower(c) && !warp_used.count(c)) {
            warp_used.insert(c);
            for (auto [nx, ny] : warp_map[c]) {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}