#include <bits/stdc++.h>
using namespace std;
#define N 505
int g[N][N], m, n, d[N][N], vis[N][N];
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

// 計算從起點能到的所有位置，並記下距離
void bfs(int r0, int c0, vector<pair<int,int>>& order) {
    queue<pair<int,int>> q;
    q.push({r0, c0});
    d[r0][c0] = 0;
    vis[r0][c0] = 1;

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        order.push_back({r, c});
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && g[nr][nc] != -1) {
                vis[nr][nc] = 1;
                d[nr][nc] = d[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}

// 傳播爆炸範圍（以曼哈頓距離為半徑）
void explosion(int r, int c, int power, vector<pair<int,int>>& affected) {
    queue<pair<int,int>> q;
    bool in_q[N][N] = {};
    int dis[N][N];
    memset(dis, -1, sizeof(dis));
    q.push({r, c});
    dis[r][c] = 0;
    in_q[r][c] = 1;
    affected.push_back({r, c});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (dis[x][y] >= power) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dr[i], ny = y + dc[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] != -1 && !in_q[nx][ny]) {
                dis[nx][ny] = dis[x][y] + 1;
                in_q[nx][ny] = 1;
                q.push({nx, ny});
                affected.push_back({nx, ny});
            }
        }
    }
}

int dfs(int r, int c) {
    if (g[r][c] == -2) return 0; // visited
    int power = g[r][c];
    g[r][c] = -2; // mark as visited
    int cnt = 1;
    if (power == 0) return cnt;

    vector<pair<int,int>> affected;
    explosion(r, c, power, affected);

    for (auto [x, y] : affected) {
        if (g[x][y] >= 0) {
            cnt += dfs(x, y);
        }
    }
    return cnt;
}

int main() {
    int req, r0, c0;
    scanf("%d%d%d", &m, &n, &req);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j] == -2) r0 = i, c0 = j;
        }

    vector<pair<int,int>> order;
    bfs(r0, c0, order); // 記錄起點能到的所有點，照距離遠近排序

    int ans = -1, total = 1;
    g[r0][c0] = 0; // 起點不能爆炸，但算已爆一格

    for (auto [r, c] : order) {
        if (g[r][c] >= 0) {
            int copied[N][N];
            memcpy(copied, g, sizeof(g)); // backup 炸彈圖
            int exploded = dfs(r, c);
            total += exploded;
            if (total >= req) {
                ans = d[r][c];
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
