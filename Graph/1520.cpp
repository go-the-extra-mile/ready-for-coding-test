#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 500;

int n, m;
int map[MAX][MAX];
int cache[MAX][MAX];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x) {
    int& res = cache[y][x];
    if (y == m-1 && x == n-1) return res = 1;
    if (res != -1) return res;

    int sum = 0;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(0 <= ny && ny < m && 0 <= nx && nx < n) {
            if (map[y][x] > map[ny][nx]) sum += dfs(ny, nx);
        }
    }

    return res = sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));

    cout << dfs(0, 0) << '\n';

    return 0;
    
}