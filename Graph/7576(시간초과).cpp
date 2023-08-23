#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

int n, m;
const int MAX = 1000;
int storage1[MAX][MAX];
int storage2[MAX][MAX];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool is_ripe(int (*storage)[MAX]) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (storage[i][j] == 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> storage1[i][j];
        }
    }

    auto before = storage1;
    auto after = storage2;
    int days = 0;
    bool exists_change;

    while(!is_ripe(before)) {
        exists_change = false;
        for (int y = 0; y < n; y++) for (int x = 0; x < m; x++) {
            if (before[y][x] == -1) {after[y][x] = -1; continue; }
            if (before[y][x] == 0) continue;

            // when before[y][x] == 1
            after[y][x] = 1;
            for (int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (0 <= ny && ny < n && 0 <= nx && nx < m && after[ny][nx] == 0) {
                    after[ny][nx] = 1;
                    exists_change = true;
                }
            }
        }

        if (!exists_change) { cout << -1 << '\n'; return 0; }
        swap(before, after);
        days++;
    }

    cout << days << '\n';
    return 0;
}