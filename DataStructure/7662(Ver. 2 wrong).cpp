/**
 * SMMH(Symmetric Min-Max Heap)을 이용한 풀이
 * 
 * SMMH란
 *  : 최솟값과 최댓값을 루트의 왼쪽, 오른쪽 자식에 저장하는 이진 트리
 * 
 * SMMH의 규칙
 *  1. 왼쪽 자식은 오른쪽 자식보다 작거나 같다.
 *  2. 조부모 g를 갖는 노드 v에 대해 g의 왼쪽 자식의 값은 v의 값보다 작거나 같다.
 *  3. 조부모 g를 갖는 노드 v에 대해 g의 오른쪽 자식의 값은 v의 값보다 크거나 같다.
 * 
 * 틀리는데 왜 틀리는지 모르겠다!!!!!!!!!
 * 
 * [알고리즘 참고자료] https://people.cs.nctu.edu.tw/~chengchc/Course_2011_Fall_DS/DS_09_Heaps.pdf
 * 
*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class SymmMinMaxHeap {
    private: 
        vector<int> v;
    public: 
        SymmMinMaxHeap(): v(2) {} // let v[0], v[1] be empty
        ~SymmMinMaxHeap() {}
        
        bool Empty() {
            return v.size() <= 2;
        }
        
        int Size() {
            return v.size() - 2;
        }

        int Min() {
            if (!Empty()) return v[2];
            return 0;
        }

        int Max() {
            if (!Empty()) {
                if (Size() >= 2) return v[3];
                else return v[2];
            }
            return 0;
        }

        int AdjSibling(int node) {
            int sib;
            if (node % 2 == 0) {
                // node is left child
                sib = node + 1;
                if (sib >= v.size()) return node; // no sibling
                if (v[node] > v[sib]) {
                    swap(v[node], v[sib]);
                    return sib;
                }
            }
            else {
                // node is right child
                sib = node -1;
                if (v[sib] > v[node]) {
                    swap(v[node], v[sib]);
                    return sib;
                }
            }

            return node;
        }

        int AdjG(int node) { 
            // adjust grandparent's left and right children with node
            if (node <= 3) return node; // no grandparent
            int grand_par = node / 2 / 2;
            int left = grand_par * 2;
            int right = grand_par * 2 + 1;

            if (v[left] > v[node]) {
                swap(v[left], v[node]);
                return left;
            }
            else if (v[node] > v[right]) {
                swap(v[node], v[right]);
                return right;
            }

            return node;
        }

        void Insert(int num) {
            v.push_back(num);
            int cur = v.size() - 1;
            int nxt;

            while(1) {
                cur = AdjSibling(cur);
                nxt = AdjG(cur);
                if (cur == nxt) break;
                cur = nxt;
            }

            // Print();
        }

        int AdjChild(int node) {
            if (node*2 >= v.size()) return node; // node is leaf = node has no child
            if (node % 2 == 0) {
                // node is left child
                int small_left = node * 2;
                int small_right = (node + 1) * 2;

                int smaller = small_left;
                if (small_right < v.size() && v[small_left] > v[small_right]) smaller = small_right;
                if (v[node] > v[smaller]) {
                    // v[node] should be the smallest
                    swap(v[node], v[smaller]);
                    return smaller;
                }
            }
            else {
                // node is right child
                int bigger_left = (node - 1) * 2 + 1;
                int bigger_right = node * 2 + 1;

                int bigger = bigger_left;
                if (bigger_right < v.size() && v[bigger_left] < v[bigger_right]) bigger = bigger_right;
                if (v[bigger] > v[node]) {
                    // v[node] should be the biggest
                    swap(v[bigger], v[node]);
                    return bigger;
                }
            }
            return node;
        }

        void DeleteMin() {
            if (Empty()) return;

            int cur = 2;
            swap(v[cur], v[v.size() - 1]);
            v.pop_back();
            int nxt;
            while(1) {
                AdjSibling(cur);
                nxt = AdjChild(cur);
                if (cur == nxt) break;
                cur = nxt;
            }

            // Print();
        }

        void DeleteMax() {
            if (Empty()) return;
            if (Size() == 1) { v.pop_back(); return; }
            
            int cur = 3;
            swap(v[cur], v[v.size() - 1]);
            v.pop_back();
            int nxt;
            while(1){
                AdjSibling(cur);
                nxt = AdjChild(cur);
                if (cur == nxt) break;
                cur = nxt;
            }

            // Print();
        }

        void Print() {
            cout << '[';
            for (int i = 2; i < v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << "]\n";
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        SymmMinMaxHeap heap;

        int k; cin >> k;
        while (k--) {
            char op; int num;
            cin >> op >> num;
            if (op == 'D') {
                if (num == -1) heap.DeleteMin();
                else if (num == 1) heap.DeleteMax();

            }
            else if (op == 'I') {
                heap.Insert(num);
            }
        }
        if (heap.Empty()) cout << "EMPTY\n";
        else cout << heap.Max() << " " << heap.Min() << '\n';
    }
    
    return 0;

}