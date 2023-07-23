/**
 * 입력의 크기로 봐서 O(N^2) 알고리즘은 시간초과될 것이고고, 원패스로 푸는 방법이 있겠거니 했다. 
 * 오른쪽의 큰 수이기 때문에 오른쪽 끝에서부터 시작해 그간 얻은 정보들을 활용하는 방법을 생각했다. 
 * A[i] < A[i+1]이면 nge(i) = A[i+1]로 쉽게 구해진다. A[i] >= A[i+1]인 경우 고민을 좀 해야한다. 
 * nge(i) = k라는 말은, 수열 A에서 A[i]와 숫자 k(A[j]라 하겠다) 사이에는 A[i] 보다 작거나 같은 수만 있다는 것을 의미한다. 
 * 그렇다면 nge(i)를 구할 때, A[i+1]에서 A[j-1]은 건너뛰어도 상관없다는 얘기가 된다. 
*/

#include <iostream>

using namespace std;

const int N_MAX = 1000000;

int a[N_MAX];
int nge[N_MAX];
int idx[N_MAX]; // nge[i]라는 수의 수열 A상 인덱스를 idx[i]에 저장

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    nge[n-1] = idx[n-1] = -1;
    for (int i=n-2; i >= 0; i--) {
        if (a[i] < a[i+1]) {
            nge[i] = a[i+1];
            idx[i] = i+1;
        }
        else {
            int cand = i + 1; // 오큰수가 될 수의 인덱스
            while (nge[cand] != -1) {
                if (a[i] < nge[cand]) break;
                cand = idx[cand]; 
            }
            nge[i] = nge[cand];
            idx[i] = idx[cand];
        }
    }

    for (int i=0; i < n; i++) cout << nge[i] << " ";
    cout << '\n';

    return 0;

}