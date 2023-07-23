/**
 * 도킹 가능한 최대 번호에 도킹하는 전략을 쓴다. 그리고 다음번에 같은 게이트에
 * 도킹하고 싶은 비행기가 오면 도킹 가능한 최대 번호 게이트를 기록한다고 생각하니
 * disjoint set을 쓰면 되겠다는 생각이 들었다. 
 * 0번 노드를 가상의 게이트로 두어 이 게이트에 도킹해야하는 상황이 온다면 공항을 폐쇄하는 논리를 쓴다. 
 * 
 * Weighted union을 못 쓰고 루트가 큰 트리가 루트가 작은 트리를 가리키도록 하는 union을 썼는데
 * 그 이유는 실제로 이 문제에서 노드 번호가 게이트 번호라는 의미를 가지고 있기 때문이다. 
 * 도킹 후, 다음 번에 그 게이트에 도킹하고 싶은 비행기가 오면 그 게이트의 (-1)번 게이트나 
 * 이 게이트가 가리키는 도킹 가능한 최대 번호 게이트에 도킹해야 한다. 
 * 
 * Weighted union을 써서 틀리는 예시를 든다. 
 * G=3, P=4일 때 gi로 3, 2, 2, 2, ...를 입력받는 경우 입력이 끝나지 않는다. 
 * gi 입력  | disjoint set 구조
 * 3        | 0,  1,  2 ← 3,  4
 * 2        | 0,  1 → 2 ← 3,  4
 * 2        | 0,  1 → 2 ← 3,  4
 * 2        | 0,  1 → 2 ← 3,  4
 * ...
*/
#include <iostream>
#include <utility>

using namespace std;

const int GMAX = 100'000;
int parent[GMAX+1];
int set_size[GMAX+1];

void left_union(int i, int j) {
    if (i == j) return;

    if (i > j) swap(i, j);

    parent[j] = i;
    set_size[i] = set_size[i] + set_size[j];
}

int find(int i) { 
    // 트리 높이를 줄여주는 collapsing find
    
    int root, trail, lead;
    for (root = i; parent[root] != -1; root = parent[root]);
    for (trail = i; trail != root; trail = lead) {
        lead = parent[trail];
        parent[trail] = root;
    }

    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g, p;
    cin >> g >> p;
    for (int i=0; i <= g; i++) {
        parent[i] = -1;
        set_size[i] = 1;
    }

    int cnt = 0;
    while (p--) {
        int mx_gate; cin >> mx_gate;
        int dock_to = find(mx_gate);

        if (dock_to == 0) break;

        cnt++;
        left_union(dock_to, find(dock_to-1));
    }

    cout << cnt << '\n';
    return 0;
}