#include <bits/stdc++.h>
using namespace std;

int N, Q;
unordered_map<int, vector<int>> x_vals;
unordered_map<int, vector<int>> y_vals;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> Q;
    int Xn, Yn;
    for(int i = 0; i < N; i++) {
        cin >> Xn >> Yn;
        x_vals[Xn].push_back(Yn);
        y_vals[Yn].push_back(Xn);
    }
    int cmd;
    while(Q--) {
        cin >> cmd;
        int x, y, X, Y;
        char c;
        if(cmd == 1) {
            cin >> x >> y;
            bool flag = false;
            for(auto &y_cord : x_vals[x]) {
                if(y_cord == y) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                cout << "salty" << "\n";
            } else {
                cout << "bland" << "\n";
            }
        } else if(cmd == 2) {
            cin >> c;
            if(c == 'X') {
                cin >> x;
                cout << x_vals[x].size() << "\n";
            } else {
                cin >> y;
                cout << y_vals[y].size() << "\n";
            }
        }
    }
    return 0;
}
