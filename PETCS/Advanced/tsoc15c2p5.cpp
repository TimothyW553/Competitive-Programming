#include <bits/stdc++.h>
using namespace std;
struct Bebilith {
    int speed, dist, sharp, id;
};
int S, N, Q;
vector<Bebilith> v;
bool cmp(Bebilith a, Bebilith b) {
    if(a.speed == b.speed) {
        if(a.speed >= S) {
            if(a.sharp != b.sharp) {
                return a.sharp < b.sharp;
            } else {
                return a.id > b.id;
            }
        } else {
            if(a.dist != b.dist) {
                return a.dist < b.dist;
            } else {
                return a.id > b.id;
            }
        }
    }
    return a.speed < b.speed;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> S >> N;
    int B, D, C;
    for(int i = 0; i < N; i++) {
        cin >> B >> D >> C;
        v.push_back(Bebilith{B, D, C, i+1});
    }
    sort(v.rbegin(), v.rend(), cmp);
    cin >> Q;
    int i;
    while(Q--) {
        cin >> i;
        cout << v[i-1].id << "\n";
    }
    return 0;
}