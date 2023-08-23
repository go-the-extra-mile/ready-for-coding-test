#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int weight[101], value[101];
int max_value[100001];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> weight[i] >> value[i];
    }

    for (int end = 1; end <= n; end++) {
        for (int filled = k; filled >= weight[end]; filled--) {
            max_value[filled] = max(value[end] + max_value[filled - weight[end]], 
                                    max_value[filled]);
        }
    }
        
	cout << max_value[k] << '\n';
}