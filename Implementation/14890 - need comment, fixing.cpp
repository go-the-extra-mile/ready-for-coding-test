#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 100;

vector<int> row[N_MAX];
vector<int> col[N_MAX];

int n, l;

bool verify(vector<int>& arr) {
    vector<bool> ramp(n);

    int cur = 1;
    int continued = 1;
    
    while (cur < n) {
        if (arr[cur-1] == arr[cur]) {
            cur++; continued++;
        }
        else if (arr[cur-1] < arr[cur]) {
            if (arr[cur] - arr[cur-1] > 1 || continued < l) return false;
            for (int i = cur - l; i < cur; i++) {
                if (ramp[i]) {
                    return false;
                }
                ramp[i] = true;
            }
            cur++; continued++;
        }
        else { // arr[cur-1] > arr[cur]
            if (arr[cur-1] - arr[cur] > 1) return false;

            // advance L칸
            ramp[cur] = true;
            cur++;
            int advanced = 1; 
            while (advanced < l) {
                if (cur >= n) return false;
                if (arr[cur-1] != arr[cur]) return false;
                ramp[cur] = true;
                cur++; advanced++;
            }
            continued = 1;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> l;
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            row[i].push_back(tmp);
            col[j].push_back(tmp);
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (verify(row[i])) res++;
        if (verify(col[i])) res++;
    }

    cout << res << '\n';

    return 0;
}