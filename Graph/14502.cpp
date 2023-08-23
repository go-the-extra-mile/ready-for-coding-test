/*
풀이 개요
    시도할 수 있는 모든 경우를 시도해보는 완전탐색으로 푼다. 
    1. 빈칸 세 곳에 벽을 세운다
    2. 바이러스를 퍼뜨린다
    3. 안전영역을 세고 최대값을 업데이트한다. 
    4. 1-3을 반복한다. 

바이러스를 퍼뜨리는 방식은 DFS로 작성했으나 탐색방법과 상관없이 잘 풀린다. 
*/
#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int original[8][8];
int map[8][8];

int v;
pii virus[10];

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int y, int x) {
    map[y][x] = 2;
    for (int dir = 0; dir < 4; dir++) {
        const auto [ny, nx] = make_pair(y + dy[dir], x + dx[dir]);
        if (0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] == 0){
            dfs(ny, nx);
        }
    }
}

void spread_virus() {
    for (int i = 0; i < v; i++) {
        pii virus_coord = virus[i];
        dfs(virus_coord.first, virus_coord.second);
    }
}

int safe_area() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) res++;
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> original[i][j];
            if (original[i][j] == 2) virus[v++] = {i, j};
        }
    }

    int mx_safe_area = 0;
    for (int i = 0; i < n*m; i++) {
        for (int j = i+1; j < n*m; j++) {
            for (int k = j+1; k < n*m; k++) {
                const auto [y1, x1] = make_pair(i / m, i % m);
                const auto [y2, x2] = make_pair(j / m, j % m);
                const auto [y3, x3] = make_pair(k / m, k % m);

                if (original[y1][x1] == 0 && original[y2][x2] == 0 && original[y3][x3] == 0) {
                    memcpy(map, original, sizeof(original));
                    map[y1][x1] = map[y2][x2] = map[y3][x3] = 1;
                    spread_virus();
                    mx_safe_area = max(mx_safe_area, safe_area());
                }
            }
        }
    }

    cout << mx_safe_area << '\n';

    return 0;
}