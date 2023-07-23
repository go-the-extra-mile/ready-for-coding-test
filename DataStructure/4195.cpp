#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

const int FMAX = 100'000;
unordered_map<string, int> pk; // pk["Barney"]: Barney의 고유번호
int parent[2*FMAX+1]; // disjoint set. parent[i]: 노드 i의 부모. NOPARENT면 루트이다
int set_size[2*FMAX+1]; // disjoint set. set_size[i]: i가 루트일 때, 그 집합의 원소의 개수

const int NOPARENT = 0; // 부모 노드 없음을 나타내는 부모 노드 번호는 0
const int FIRSTPK = 1; // 고유번호는 1부터 시작

int weighted_union(int i, int j) {
    // 작은 트리의 루트의 부모를 큰 트리의 루트로 설정하는 weighted union
    // i, j는 트리의 루트 번호여야 한다

    if (i == j) return set_size[i];

    int sum = set_size[i] + set_size[j];
    if (set_size[i] > set_size[j]) {
        parent[j] = i;
        set_size[i] = sum;
    }
    else {
        parent[i] = j;
        set_size[j] = sum;
    }
    return sum;
}

int find(int i) { 
    // 트리 높이를 줄여주는 collapsing find
    
    int root, trail, lead;
    for (root = i; parent[root] != NOPARENT; root = parent[root]);
    for (trail = i; trail != root; trail = lead) {
        lead = parent[trail];
        parent[trail] = root;
    }

    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, f;
    cin >> t;
    while(t--) {
        cin >> f;
        string first, second;

        int cur_pk = FIRSTPK;
        while(f--) {
            cin >> first >> second;
            if (pk.count(first) == 0) {
                pk[first] = cur_pk;
                parent[cur_pk] = NOPARENT;
                set_size[cur_pk] = 1;
                cur_pk++;
            }
            if (pk.count(second) == 0) {
                pk[second] = cur_pk;
                parent[cur_pk] = NOPARENT;
                set_size[cur_pk] = 1;
                cur_pk++;
            }

            cout << weighted_union(find(pk[first]), find(pk[second])) << '\n';
        }
        pk.clear();
    }

}