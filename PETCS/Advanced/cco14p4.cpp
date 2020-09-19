#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
struct Planet { int a, b; friend bool operator<(const Planet &x, const Planet &y) { return x.b > y.b; } };
int N, P, visCnt = 1, fuelCnt = 0; priority_queue<Planet> q;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> P;
    for(int i = 1, a, b; i <= N; i++) {
        cin >> a >> b;
        if(i == P) {
            fuelCnt += a;
        } else if(a >= b) {
            q.push((Planet){a, b});
        }
    }
    while(!q.empty()) {
        int a = q.top().a, b = q.top().b; q.pop();
        if(fuelCnt >= b) {
            fuelCnt += (a - b);
            visCnt++;
        }
    }
    cout << fuelCnt << "\n";
    cout << visCnt << "\n";
    return 0;
}
