#include <bits/stdc++.h>
using namespace std;
const int MAX = (1<<22);
int N, dist[MAX];
queue<int> q;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    while(1) {
        memset(dist, 0x3f, sizeof dist);
        cin >> N;
        if(N == 0) {
            break;
        }
        int start = 0;
        for(int i = 0, m; i < N; i++) {
            cin >> m; m--;
            start |= (i << (m*3)); // three bits each m
        }
        dist[start] = 0;
        q.push(start);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i = 0; i < N; i++) {
                int loc = (cur >> (3*i))&7; // which coin to move
                bool can = true; // at location, make sure there is no lower value coin than i at same location
                for(int j = 0; j < i; j++) { // cannot move this coin underneath
                    if(((cur >> (j*3))&7) == loc) {
                        can = false;
                    }
                }
                if(!can) {
                    continue;
                }
                if(loc + 1 < N) {
                    int nx = (cur^(loc << (3*i))) | ((loc+1)<<(3*i)); // remember old location
                    bool flag = true;
                    for(int j = 0; j < i; j++) {
                        if(((cur >> (j*3))&7) == (loc+1)) {
                            flag = false;
                            break;
                        }
                    }
                    if(dist[cur] + 1 < dist[nx] && flag) {
                        dist[nx] = dist[cur] + 1;
                        q.push(nx);
                    }
                }
                if(loc - 1 >= 0) {
                    int nx = (cur^(loc << (3*i))) | ((loc-1)<<(3*i));
                    bool flag = true;
                    for(int j = 0; j < i; j++) {
                        if(((cur >> (j*3))&7) == (loc-1)) {
                            flag = false;
                            break;
                        }
                    }
                    if(dist[cur] + 1 < dist[nx] && flag) {
                        dist[nx] = dist[cur] + 1;
                        q.push(nx);
                    }
                }
            }
        }
        int end = 0;
        for(int i = 0; i < N; i++) {
            end |= (i << (i*3));
        }
        if(dist[end] == 0x3f3f3f3f) {
            cout << "IMPOSSIBLE" << "\n";
        } else {
            cout << dist[end] << "\n";
        }
    }
    return 0;
}
