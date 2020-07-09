#include <bits/stdc++.h>
using namespace std;

stack<string> dir;
stack<string> loc;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    loc.push("HOME");
    while(1) {
        string s; cin >> s;
        if(s == "L" or s == "R") {
            dir.push(s);
        } else if(s == "SCHOOL") {
            break;
        } else {
            loc.push(s);
        }
    }
    while(!dir.empty()) {
        if(dir.top() == "R") {
            cout << "Turn LEFT ";
        } else {
            cout << "Turn RIGHT ";
        }
        dir.pop();
        if(loc.top() == "HOME") {
            cout << "into your HOME." << "\n"; 
        } else {
            cout << "onto " << loc.top() << " street." << "\n";
        }
        loc.pop();
    }
    return 0;
}
