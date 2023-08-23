#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

const int N_MAX = 50;
const int M_MAX = 13;
const int INF = 987654321;


vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;
int chicken_dist[2*N_MAX];

int n, m;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int type;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> type;
            if (type == 1) homes.push_back({i, j});
            else if (type == 2) chickens.push_back({i, j});
        }
    }

    string select = string(chickens.size() - m, '0') + string(m, '1');

    int res = INF;
    do {
        for(int i = 0; i < homes.size(); i++) chicken_dist[i] = INF;

        for(int i = 0; i < chickens.size(); i++) {
            if (select[i] == '0') continue;
            for (int j = 0; j < homes.size(); j++) {
                const auto [chicken_y, chicken_x] = chickens[i];
                const auto [home_y, home_x] = homes[j];
                chicken_dist[j] = min(chicken_dist[j], abs(chicken_y - home_y) + abs(chicken_x - home_x));
            }
        }

        int city_chicken_dist = 0;
        for(int i = 0; i < homes.size(); i++) city_chicken_dist += chicken_dist[i];
        res = min(res, city_chicken_dist);
        
    } while (next_permutation(begin(select), end(select)));

    cout << res << '\n';

    return 0;

}