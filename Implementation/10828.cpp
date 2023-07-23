#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

vector<string> split(string str, char delim){
    stringstream ss(str);
    vector<string> ans;
    for(string word; getline(ss, word, delim); ){
        ans.push_back(word);
    }
    
    return ans;
}

int main(){
    int n;
    string full_cmd;
    // getline(cin, full_cmd, '\n');
    // n = stoi(full_cmd);
    cin >> n;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    stack<int> stk;
    vector<string> cmds;
    string cmd;
    for(int i=0; i<n; i++){
        getline(cin, full_cmd, '\n');
        cmds = split(full_cmd, ' ');

        cmd = cmds[0];
        if (cmd == "push"){
            stk.push(stoi(cmds[1]));
        }
        else if (cmd == "pop"){
            if (stk.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << stk.top() << '\n';
                stk.pop();
            }
        }
        else if (cmd == "size"){
            cout << stk.size() << '\n';
        }
        else if (cmd == "empty"){
            if (stk.empty()){
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (cmd == "top"){
            if (stk.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << stk.top() << '\n';
            }
        }
        else {
            cout << "wrong input" << '\n';
            return 1;
        }
    }

    return 0;
}