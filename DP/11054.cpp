/*
수열의 각 숫자를 마지막 원소로 갖는 가장 긴 부분수열의 길이를 가지고 있다면 
가장 긴 증가하는 부분수열의 길이 문제를 풀 수 있다. 
가장 긴 증가하는 부분수열의 길이, 그리고 가장 긴 감소하는 부분수열의 길이를 가지고 있으면
가장 긴 바이토닉 부분수열의 길이를 알 수 있다. 

가장 긴 감소하는 부분수열은 가장 긴 증가하는 부분수열과 같은 방법으로 풀 수 있다. 

따라서 가장 긴 증가하는 부분수열의 길이 문제를 풀자. 
lis_len[i]: arr[i]를 마지막 원소로 갖는 가장 긴 부분수열의 길이라 하자. 
lis_len[i] = max { lis_len[j] for j = 0~(i-1) if arr[j] < arr[i] }이다. 

시간복잡도: O(N^2)
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_LEN = 1000;
int arr[MAX_LEN];

// lis_len[i]: arr[i]를 마지막 원소로 갖는 가장 긴 부분수열의 길이
int lis_len[MAX_LEN]; 
// rev_lis_len[i]: arr를 뒤에서부터 본다고 하자. arr[i]를 마지막 원소로 갖는 가장 긴 부분수열의 길이
int rev_lis_len[MAX_LEN]; 

int main() {
    cin.tie(0)->sync_with_stdio(0);    
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) mx = max(mx, lis_len[j]);
        }
        lis_len[i] = mx + 1;
    }

    for (int i = n-1; i >= 0; i--) {
        int mx = 0;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[i]) mx = max(mx, rev_lis_len[j]);
        }
        rev_lis_len[i] = mx + 1;
    }

    int mx_bitonic_len = 0;
    for (int i = 0; i < n; i++) {
        mx_bitonic_len = max(mx_bitonic_len, lis_len[i] + rev_lis_len[i] - 1);
    }

    cout << mx_bitonic_len << '\n';

    return 0;
}