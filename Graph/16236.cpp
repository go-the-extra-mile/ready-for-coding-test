#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 20;
int map[MAX][MAX];
bool visited[MAX][MAX];

typedef tuple<int, int, int> tiii;

int n;

int shark_size; 

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

/*
    상어가 (y, x)에서 출발해 먹을 물고기 한 마리를 찾는다
    리턴값: {먹을 물고기의 y좌표, x좌표, 거리}
*/ 
tiii bfs(int y, int x) {
    queue<tiii> q;
    memset(visited, 0, sizeof(visited));

    tiii fish_to_eat = {MAX, MAX, 0}; // 리턴하는 값. 먹을 물고기가 없으면 초기화값 그대로 리턴하게 됨
    q.push({y, x, 0});
    visited[y][x] = true;
    int cur_dist = 1; // cur_dist 거리에 있는 좌표에서 먹을 물고기를 찾는다
    while (!q.empty()) {
        const auto [y, x, dist] = q.front(); q.pop();

        if (dist > cur_dist) { // 처음으로 큐에서 cur_dist보다 먼 좌표가 나옴
            // cur_dist 거리에 먹을 물고기가 있었는지 확인
            const auto [fish_y, fish_x, fish_dist] = fish_to_eat;
            if (fish_y < n) { // 있었다 -> 이 물고기를 먹는다
                return fish_to_eat;
            }
            else { // 없었다 -> (cur_dist + 1) 거리에 있는 좌표에서 먹을 물고기를 찾기 시작한다
                cur_dist++;
            }
        }

        if (1 <= map[y][x] && map[y][x] < shark_size) { // 먹을 수 있음
            const auto [fish_y, fish_x, fish_dist] = fish_to_eat;

            if (y < fish_y || (y == fish_y && x < fish_x)) { // 더 왼쪽 위에 있는 물고기라면
                fish_to_eat = {y, x, dist};
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            const auto [ny, nx, ndist] = make_tuple(y + dy[dir], x + dx[dir], dist + 1);
            if (0 <= ny && ny < n && 0 <= nx && nx < n && !visited[ny][nx]) {
                if (map[ny][nx] <= shark_size) { // unvisited, 지나갈 수 있다면
                    q.push({ny, nx, ndist});
                    visited[ny][nx] = true;
                }
            }
        }
    }

    // 큐가 비었더라도 먹을 물고기가 없다는 말이 아님
    /*  example
        0 0 1
        0 0 0
        0 9 0
    */
    return fish_to_eat; 

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int y, x; // 아기 상어 위치
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                map[i][j] = 0;
                y = i; x = j;
            }
        }
    }

    bool exists_fish; // 먹을 물고기가 있음
    int res = 0; 
    int ate = 0; // 먹은 물고기 수
    shark_size = 2;
    do {
        const auto [fish_y, fish_x, dist] = bfs(y, x);

        if (exists_fish = (fish_y < n)) { // 먹을 물고기가 없으면 bfs()는 {MAX, MAX, 0}을 리턴함
            ate++;
            res += dist;
            if (ate == shark_size) {
                shark_size++;
                ate = 0;
            }
            y = fish_y; x = fish_x;
            map[y][x] = 0;
        }
    } while(exists_fish);

    cout << res << '\n';

    return 0;
}