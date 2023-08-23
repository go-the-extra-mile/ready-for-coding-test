#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int n;
int map[20][20];
bool visited[20][20];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    queue<tiii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                q.push({i, j, 0});
                visited[i][j] = true;
                map[i][j] = 0;
            }
        }
    }

    int ate = 0;
    int time = 0;
    int shark_size = 2;
    int cur_dist = 1;
    vector<pii> fish;
    
    while(1) {
        while (!q.empty()) {
            tiii cur = q.front(); q.pop();
            const auto [y, x, dist] = cur;

            cout << y << ", " <<  x << ", " << dist << '\n';

            if (dist > cur_dist) {
                // fish has list of fish at cur_dist
                auto [eat_y, eat_x] = make_pair(20, 20);
                for (auto [y, x]: fish) {
                    if (eat_y > y || (eat_y == y && eat_x > x)) {
                        eat_y = y; eat_x = x;
                    }
                }
                if (eat_y != 20 || eat_x != 20) { // exists fish to eat
                    fish.clear();
                    ate += 1;
                    if (ate >= shark_size) {
                        ate = 0; shark_size++;
                    }
                    time += cur_dist;

                    map[eat_y][eat_x] = 0;
                    while (!q.empty()) q.pop();
                    q.push({eat_y, eat_x, 0});
                    memset(visited, 0, sizeof(visited));
                    visited[eat_y][eat_x] = true;
                    cur_dist = 1;
                }
                else { // no fish to eat -> keep looking further
                    cur_dist++;
                }
            }

            if (1 <= map[y][x] && map[y][x] < shark_size) {
                // eatable
                fish.push_back({y, x});
                
                cout << "push back fish" << y << " " << x << '\n';
            }

            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                int ndist = dist + 1;
                if (0 <= ny && ny < n && 0 <= nx && nx < n && !visited[ny][nx]) {
                    q.push({ny, nx, ndist});
                    visited[ny][nx] = true;
                }
            }
        }

        if (!fish.empty()) { // exists fish to eat
            cout << "Here" << '\n';

            auto [eat_y, eat_x] = make_pair(20, 20);
            for (auto [y, x]: fish) {
                if (eat_y > y || (eat_y == y && eat_x > x)) {
                    eat_y = y; eat_x = x;
                }
            }

            fish.clear();
            ate += 1;
            if (ate >= shark_size) {
                ate = 0; shark_size++;
            }
            time += cur_dist;

            map[eat_y][eat_x] = 0;
            while (!q.empty()) q.pop();
            q.push({eat_y, eat_x, 0});
            memset(visited, 0, sizeof(visited));
            visited[eat_y][eat_x] = true;

            cur_dist = 1;
        }
        else { // no fish to eat
            break;
        }
    }
    

    cout << time << '\n';
    return 0;
}