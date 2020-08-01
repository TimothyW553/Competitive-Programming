#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int N, P; vector<pair<string, int>> v;
bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> P;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        v.push_back({s, 0});
    }
    int time;
    for(int i = 0; i < P; i++) {
        for(int j = 0; j < N; j++) {
            cin >> time;
            v[j].second += time;
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < N; i++) {
        cout << i+3 << ". " << v[i].first << "\n";
    }
    return 0;
}
