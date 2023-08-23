#include <iostream>
#include <cstring>

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

const int MAX = 1000;
int map[MAX][MAX];
bool cache[MAX][MAX][2];

int n, m;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cache[i][j];
        }
    }
}