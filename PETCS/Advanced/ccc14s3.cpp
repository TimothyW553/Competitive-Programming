#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while(T--) {
        stack<int> mountain, lake;
        cin >> N;
        for(int i = 0, m; i < N; i++) {
            cin >> m;
            mountain.push(m);
        }
        int count = 1;
        while(!mountain.empty()) {
            if(mountain.top() == count) {
                mountain.pop();
                count++;
            } else if(!lake.empty() and lake.top() == count) {
                lake.pop();
                count++;
            } else {
                lake.push(mountain.top());
                mountain.pop();
            }
        }
        bool flag = true;
        while(!lake.empty()) {
            if(lake.top() == count) {
                lake.pop();
                count++;
            } else {
                flag = false;
                lake.pop();
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