#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 10000;

int d(int n);

int main(){
    vector<bool> is_self(MAX+1, true); // is_self[n]: true then n is self number
    for(int n=1; n <= MAX; n++){
        int dn = d(n);
        if(dn <= MAX)
            is_self[d(n)] = false;
    }
    for(int n=1; n <= MAX; n++){
        if(is_self[n]){
            cout << n << '\n';
        }
    }
    
    return 0;
}

int d(int n){
    int ans = n;
    string n_str = to_string(n);
    for(char jarisu : n_str){
        ans += (int)(jarisu - '0');
    }
    
    return ans;
}
