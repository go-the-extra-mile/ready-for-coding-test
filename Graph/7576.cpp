/*
창고에 '1'인 좌표를 queue에 넣는 방식으로 BFS 풀이. 
queue에서 '1'인 좌표를 꺼내 주위의 '0'인 좌표를 '1'로 set, 그리고 다시 queue에 넣는 것을 반복한다. 

익은 날을 계산하기 위해 이차원 배열 ripe_day를 활용한다. 
ripe_day[i][j]에는 (i, j)가 익은 날을 저장한다. 
따라서 시작부터 '1'인 좌표는 ripe_day에 0이 들어간다. 나머지 좌표는 -1로 초기화한다. 
'1'인 좌표 (y, x) 주위의 '0'인 좌표 (ny, nx)를 '1'로 set하면서
ripe_day[ny][nx] = ripe_day[y][x] + 1로 업데이트한다. 
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
const int MAX = 1000;
int storage[MAX][MAX];
int ripe_day[MAX][MAX];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

queue<pii> q;

void print_arr(int (*storage)[MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << storage[i][j] << "\t";
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(ripe_day, -1, sizeof(ripe_day));
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> storage[i][j];
            if (storage[i][j] == 1) {
                ripe_day[i][j] = 0; 
                q.push({i, j}); 
            }
        }
    }

    while(!q.empty()) {
        const auto [y, x] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++){
            const auto ny = y + dy[dir];
            const auto nx = x + dx[dir];

            if (0 <= ny && ny < n && 0 <= nx && nx < m && storage[ny][nx] == 0){
                storage[ny][nx] = 1;
                ripe_day[ny][nx] = ripe_day[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    int res = ripe_day[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] == 0) {cout << -1 << '\n'; return 0; }
            res = max(res, ripe_day[i][j]);
        }
    }

    cout << res << '\n';

    return 0;
}