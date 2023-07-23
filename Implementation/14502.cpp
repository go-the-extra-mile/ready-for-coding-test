#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

int n, m;
int map[8][8];
int map_copy[8][8];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void make_copy(){
    for (int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            map_copy[i][j] = map[i][j];
        }
    }
    
    return;
}

void dfs(int i, int j){
    map_copy[i][j] = 2;
    for (int mv=0; mv < 4; mv++){
        int next_i = i + dy[mv];
        int next_j = j + dx[mv];
        if (0 <= next_i && next_i < n && 0 <= next_j && next_j < m && map_copy[next_i][next_j] == 0){
            dfs(next_i, next_j);
        }
    }
}

void spread_virus(){
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            if (map_copy[i][j] == 2){
                dfs(i, j);
            }
        }
    }
}

int count_safe(int map[8][8]){
    int cnt = 0;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            if (map[i][j] == 0) cnt++;
        }
    }
    
    return cnt;
}

pair<int, int> to_coord(int num){
    int y = num / m;
    int x = num % m;
    return make_pair(y, x);
}

int main(){
    
    cin >> n >> m;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            cin >> map[i][j];
        }
    }
    
    int mx_safe = -1;
    for (int i=0; i < n*m; i++){
        for (int j=i+1; j < n*m; j++){
            for (int k=j+1; k < n*m; k++){
                const auto [y1, x1] = to_coord(i);
                const auto [y2, x2] = to_coord(j);
                const auto [y3, x3] = to_coord(k);
                
                if (map[y1][x1] == 0 && map[y2][x2] == 0 && map[y3][x3] == 0){ // wallable
                    map[y1][x1] = map[y2][x2] = map[y3][x3] = 1;
                    make_copy();
                    
                    spread_virus();
                    
                    int safe = count_safe(map_copy);
                    if (safe > mx_safe) {
                        mx_safe = safe;
                    }
                    
                    map[y1][x1] = map[y2][x2] = map[y3][x3] = 0;
                }
            }
        }
    }
    
    cout << mx_safe << '\n';
}