#include <bits/stdc++.h>
using namespace std;

bool tasty(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { // b
    return a.second.second < b.second.second;
}

bool filling(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { // a
    return a.second.first < b.second.first;
}

int N;
vector<pair<int, pair<int, int>>> v;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    int a, b;
    for(int i = 1; i <= N; i++) {
        cin >> a >> b;
        v.push_back({i, {a, b}});
    }
    sort(v.begin(), v.end(), filling);
    for(auto &x : v) {
        cout << x.first << " ";
    }
    cout << "\n";
    sort(v.begin(), v.end(), tasty);
    for(auto &x : v) {
        cout << x.first << " ";
    }
    return 0;
}
