#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

int N, P,
          a[101][101];
vector<pair<string, int>> ranks;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N >> P;
    for(int i = 0; i < N; i++) {
        string name; cin >> name;
        ranks.push_back({name, 0});
    }
    for(int i = 0; i < P; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = 0; j < P; j++) {
            sum += a[j][i];
        }
        ranks[i].second = sum;
    }
    sort(ranks.begin(), ranks.end(), cmp);
    for(int i = 0; i < N; i++) {
        cout << i+3 << ". " << ranks[i].first << "\n";
    }
    return 0;
}
