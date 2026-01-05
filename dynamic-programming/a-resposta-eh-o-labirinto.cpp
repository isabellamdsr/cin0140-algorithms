#include <iostream>
#include <vector>
using namespace std;

void find(vector<string> &laby, int n, int m, vector<pair<int,int>> &E) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (laby[i][j] == '@')
                E.push_back({i, j});
}

bool dfs(int r, int c, int s, int t, vector<string> &laby, bool V[41][41][21][2], int n, int m, int j) {
    if (s > j) return false;
    if (V[r][c][s][t]) return false;

    V[r][c][s][t] = true;

    if (laby[r][c] == 'x') t = 1;

    if (t == 1 && laby[r][c] == '@') return true;

    int drow[4] = {1, -1, 0, 0};
    int dcol[4] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int nr = r + drow[k];
        int nc = c + dcol[k];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (laby[nr][nc] == '#') continue;

        int ns = s + (laby[nr][nc] == 's');

        if (dfs(nr, nc, ns, t, laby, V, n, m, j)) return true;
    }
    return false;
}

int main() {
    int n, m, j;
    cin >> n >> m >> j;

    vector<string> laby(n);
    for (int i = 0; i < n; i++)
        cin >> laby[i];

    vector<pair<int,int>> E;
    find(laby, n, m, E);

    for (int a = 0; a < E.size(); a++) {
        bool V[41][41][21][2] = {};

        if (dfs(E[a].first, E[a].second, 0, 0, laby, V, n, m, j)) {
            cout << "SUCCESS";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
