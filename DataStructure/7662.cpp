#include <iostream>
#include <map>
#include <iterator>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void printmap(multimap<int, int>& map) {
    for (auto it = map.begin(); it != end(map); it++){
        cout << (*it).first << ' ';
    }
    cout << '\n';
}

int main(){
    fastio; 
    int t;
    cin >> t; 

    while(t--) {
        multimap<int, int> mmap;

        int k;
        cin >> k;

        while (k--){
            char op;
            int n;
            cin >> op >> n; 
            
            if (op == 'I') {
                mmap.insert({n, n});
            }
            else if (op == 'D') {
                if (mmap.size() == 0) {
                    continue;
                }
                if (n == 1) mmap.extract(prev(end(mmap)));
                else mmap.extract(begin(mmap));
            }
        }

        if (mmap.size() == 0) cout << "EMPTY\n";
        else cout << mmap.rbegin()->first << ' ' << mmap.begin()->first << '\n';
    }
}