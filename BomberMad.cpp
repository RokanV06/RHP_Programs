#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<bool> bombRow(H, false);

    vector<bool> bombCol(W, false);

 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                bombRow[i] = true;
                bombCol[j] = true;
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));

    queue<pair<int, int>> q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            if (S[i][j] == '.' &&
                !bombRow[i] &&
                !bombCol[j]) {

                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Multi-source BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (dist[x][y] == K)
            continue;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= H ||
                ny < 0 || ny >= W)
                continue;

            // Cannot move onto a bomb
            if (S[nx][ny] == '#')
                continue;

            // Already visited
            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    // Count cells that can reach a safe cell within K moves
    long long ans = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.' && dist[i][j] != -1) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
