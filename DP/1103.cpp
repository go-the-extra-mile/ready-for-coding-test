/*
각 좌표에서 움직일 수 있는 최대 횟수(부분문제)를 풀고 cache에 저장한다. 
보드는 DFS로 탐색한다. 
싸이클을 감지하기 위한 visit 배열을 사용한다. 
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;

char board[50][50];
int n, m;

int moves[50][50][4]; // moves[y][x][dir] = (y, x)에서 dir 방향으로 움직일 수 있는 최대 횟수(부분문제)
int cache[50][50]; // cache[y][x] = (y, x)에서 움직일 수 있는 최대 횟수(부분문제) = max({moves[y][x][0:4]})

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool visit[50][50]; // 싸이클을 감지하기 위해

int dfs(int y, int x) {
    if (visit[y][x]) return cache[y][x] = INF; // 싸이클

    if (board[y][x] == 'H') return 0;
    if (cache[y][x] != 0) return cache[y][x];

    visit[y][x] = true;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir] * board[y][x];
        int nx = x + dx[dir] * board[y][x];

        if (0 <= ny && ny < n && 0 <= nx && nx < m) { // in board
            moves[y][x][dir] = dfs(ny, nx) + 1;
        }
        else { // out of board
            moves[y][x][dir] = 1;
        }
    }
    visit[y][x] = false;
    
    return cache[y][x] = *max_element(moves[y][x], moves[y][x] + 4); 
}

int main() {
    cin >> n >> m;

    char ch;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> ch;
            board[i][j] = ((ch == 'H')? ('H') : (ch - '0'));
        }
    }

    int result = dfs(0, 0);
    if (result >= INF) cout << -1 << '\n';
    else cout << result << '\n';

    return 0;
}