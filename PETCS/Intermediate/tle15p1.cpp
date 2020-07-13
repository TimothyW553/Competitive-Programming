#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int N, P;
pair<string, int> v[MAX];
bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> P;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        v[i] = {s, 0};
    }
    int time;
    for(int i = 0; i < P; i++) {
        for(int j = 0; j < N; j++) {
            cin >> time;
            v[j].second += time;
        }
    }
    sort(v, v+N, cmp);
    for(int i = 0; i < N; i++) {
        cout << i+3 << ". " << v[i].first << "\n";
    }
    return 0;
}
