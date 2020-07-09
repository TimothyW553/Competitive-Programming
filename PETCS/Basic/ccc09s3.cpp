#include <bits/stdc++.h>
using namespace std;
const int MM = 50;
bool mat[MM][MM];
void add(int x, int y) {
    mat[x][y] = 1; mat[y][x] = 1;
}
void remove(int x, int y) {
    mat[x][y] = 0; mat[y][x] = 0;
}
int getFriends(int x) {
    int tot = 0;
    for(int i = 1; i < 50; i++) {
        if(mat[x][i] == 1) {
            tot++;
        }
    }
    return tot;
}
int getFoF(int x) {
    set<int> st;
    for(int i = 1; i < 50; i++) {
        if(mat[x][i] == 1) {
            for(int j = 1; j < 50; j++) {
                if(mat[i][j] == 1 and j != x and mat[x][j] == 0) {
                    st.insert(j);
                }
            }
        }
    }
    return st.size();
}
int getDeg(int x, int y) {
    int dist[50];
    fill(dist, dist+50, 0);
    dist[x] = 1;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == y) {
            break;
        }
        for(int i = 1; i < 50; i++) {
            if(mat[cur][i] and dist[i] == 0) {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    return dist[y]-1;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    add(1,6);
    add(2,6);
    add(3,4);
    add(3,5);
    add(3,6);
    add(3,15);
    add(4,5);
    add(4,6);
    add(5,6);
    add(6,7);
    add(7,8);
    add(8,9);
    add(9,10);
    add(9,12);
    add(10,11);
    add(11,12);
    add(12,13);
    add(13,14);
    add(13,15);
    add(16,17);
    add(16,18);
    add(17,18);
    char c;
    while(1) {
        cin >> c; 
        int x, y;
        if(c == 'q') {
            break;
        } else if(c == 'i') {
            cin >> x >> y;
            add(x, y);
        } else if(c == 'd') {
            cin >> x >> y;
            remove(x, y);
        } else if(c == 'n') {
            cin >> x;
            cout << getFriends(x) << "\n";
        } else if(c == 'f') {
            cin >> x;
            cout << getFoF(x) << "\n";
        } else if(c == 's') {
            cin >> x >> y;
            int deg = getDeg(x, y);
            if(deg == -1) {
                cout << "Not connected" << "\n";
            } else {
                cout << deg << "\n";
            }
        }
    }
    return 0;
}