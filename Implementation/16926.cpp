/*
    예시: 다음 배열을 2번 회전
        1   2   3   4
        5   6   7   8
        9   10  11  12
        13  14  15  16
    1. 화살표로 연결된 각 사각형을 화살표 순서가 유지되도록 일자로 편다. 
        사각형의 가장 왼쪽 위 요소가 펼쳤을 때 가장 앞에 오도록 펼친다. 
        바깥 사각형을 펼친 것: 1 2 3 4 8 12 16 15 14 13 9 5
        안쪽 사각형을 펼친 것: 6 7 11 10
        
    2. 각 사각형을 R번 회전시킨다. 
        사각형을 펼친 것을 선이라 부르자. 일단 R이 선의 길이와 같을 경우 회전시키지 않은 것과 같다. 
        R번 회전시키는 것은 펼친 선의 첫 R개의 요소를 떼서 선 맨 뒤에 붙이는 것과 같다. 
        이와 같은 효과를 내기 위해 선을 읽을 때 R번째 요소가 첫번째 요소인 것처럼 읽고, 
        선의 끝에 도달하면 첫 요소부터 (R-1)번째 요소까지 읽으면 된다. 

        바깥 사각형을 2번 회전시킨 것을 펼친 것: 3 4 8 12 16 15 14 13 9 5 1 2
        안쪽 사각형을 2번 회전시킨 것을 펼친 것: 11 10 6 7

    3. 결과 배열에 채우고 출력한다. 
        1단계를 위해 배열을 읽은 순서와 같은 순서로 결과 배열에 쓰면 된다. 
        3       4       8       12
        2       11      10      16
        1       7       6       15
        5       9       13      14

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 300;
vector<int> straightened[N_MAX/2];
int start_idx[N_MAX/2];

int n, m, r;

int arr[N_MAX][N_MAX];
int res[N_MAX][N_MAX];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // 1. 각 사각형을 일자로 펴기

    int smaller = min(n, m);
    int height = n;
    int width = m;
    for (int i = 0; i <= smaller/2 - 1; i++) {
        // a box that starts at (i, i)
        auto& line = straightened[i];

        for (int x = i, moves = 0; moves < width; x++, moves++) {
            line.push_back(arr[i][x]);
        }
        for (int y = i+1, moves = 0; moves < height-1; y++, moves++) {
            line.push_back(arr[y][i+width-1]);
        }
        for (int x = i+width-2, moves = 0; moves < width-1; x--, moves++) {
            line.push_back(arr[i+height-1][x]);
        }
        for (int y = i+height-2, moves = 0; moves < height-2; y--, moves++) {
            line.push_back(arr[y][i]);
        }

        height -= 2;
        width -= 2;
    }

    // 2. R번 회전

    for (int i = 0; i <= smaller/2 - 1; i++) {
        int len = straightened[i].size();
        start_idx[i] = r % len;
    }

    // 3. 결과 배열 채우기

    height = n;
    width = m;
    for (int i = 0; i <= smaller/2 - 1; i++) {
        // a box that starts at (i, i)
        auto& line = straightened[i];

        int idx = start_idx[i];
        int len = straightened[i].size();

        for (int x = i, moves = 0; moves < width; x++, moves++) {
            res[i][x] = line[idx];
            idx = (idx + 1) % len;
        }
        for (int y = i+1, moves = 0; moves < height-1; y++, moves++) {
            res[y][i+width-1] = line[idx];
            idx = (idx + 1) % len;
        }
        for (int x = i+width-2, moves = 0; moves < width-1; x--, moves++) {
            res[i+height-1][x] = line[idx];
            idx = (idx + 1) % len;
        }
        for (int y = i+height-2, moves = 0; moves < height-2; y--, moves++) {
            res[y][i] = line[idx];
            idx = (idx + 1) % len;
        }

        height -= 2;
        width -= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;

}