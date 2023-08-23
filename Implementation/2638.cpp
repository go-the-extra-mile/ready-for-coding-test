/*
    남은 치즈가 있을 때: 
        1. 외부공기를 표시한다. 
        2. 외부공기와 맞닿은 면이 2개 이상인 치즈를 표시한다. 
        3. 표시한 치즈를 제거한다. 
    
    1단계는 (0, 0)에서부터 치즈인 곳을 제외한 곳을 방문하는 DFS(BFS도 무관)로 해결했다. 
    2-3단계는 좌표의 배열인 to_vanish를 두어 한 싸이클마다 제거될 치즈의 좌표를 기록한 뒤
    한번에 제거했다. 제거할 치즈임을 확인한 순간에 바로 제거하면 옆에 있는 치즈의 제거 여부에
    영향을 주므로 그렇게 하면 안된다. 
*/
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
const int N_MAX = 100;

bool map[N_MAX][N_MAX]; // map[i][j]: 0은 공기, 1은 치즈
bool ext_air[N_MAX][N_MAX]; // ext_air[i][j] = true면 (i, j)가 외부공기라는 뜻. false면 내부공기거나 치즈
int exposed[N_MAX][N_MAX]; // exposed[i][j]: 치즈 (i, j)의 외부공기 접촉 면 수수

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m;

void dfs(int y, int x) {
    ext_air[y][x] = true;

    for (int dir = 0; dir < 4; dir++) {
        const auto [ny, nx] = make_pair(y + dy[dir], x + dx[dir]);
        // ext_air가 visited 역할을 한다
        // 치즈를 피해 DFS한다
        if(0 <= ny && ny < n && 0 <= nx && nx < m && !ext_air[ny][nx]) {
            if (!map[ny][nx]) dfs(ny, nx);
            else exposed[ny][nx]++;
            //   ^ 2. 외부공기와 맞닿은 면이 2개 이상인 치즈를 표시한다. 
            // 치즈의 외부공기 접촉면 수를 1 추가한다. 
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int left_cheese = 0; // 맵에 존재하는 치즈 수
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j]) left_cheese++;
        }
    }

    int t = 0;
    while (left_cheese) {
        // 1. 외부공기를 표시한다. ~ 2. 외부공기와 맞닿은 면이 2개 이상인 치즈를 표시한다. 
        dfs(0, 0);
        
        // 3. 표시한 치즈를 제거한다. 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (exposed[i][j] >= 2) {
                    map[i][j] = 0;
                    left_cheese--;
                }
            }
        }

        memset(ext_air, 0, sizeof(ext_air));
        memset(exposed, 0, sizeof(exposed));
        t++;
    }

    cout << t << '\n';

    return 0;
}