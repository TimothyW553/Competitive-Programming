#include <bits/stdc++.h>
using namespace std;

int T;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> T;
    int N;
    while(T--) {
        cin >> N;
        stack<int> mountain;
        stack<int> branch;
        int m;
        for(int i = 0; i < N; i++) {
            cin >> m;
            mountain.push(m);
        }
        int count = 1;
        while(!mountain.empty()) {
            if(mountain.top() == count) {
                mountain.pop();
                count++;
            } else if(!branch.empty() and branch.top() == count) {
                branch.pop();
                count++;
            } else {
                branch.push(mountain.top());
                mountain.pop();
            }
        }
        bool flag = true;
        while(!branch.empty()) {
            if(branch.top() == count) {
                branch.pop();
                count++;
            } else {
                flag = false;
                branch.pop();
            }
        }
        if(flag) {
            cout << "Y" << "\n";
        } else {
            cout << "N" << "\n";
        }
    }
    return 0;
}
