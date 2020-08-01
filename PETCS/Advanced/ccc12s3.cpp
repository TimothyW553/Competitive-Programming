#include <bits/stdc++.h>
using namespace std;
int N; map<int, int> freq;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first > b.first;
    } else {
        return a.second < b.second;
    }
}
vector<pair<int, int>> sort(map<int, int> &mp) {
    vector<pair<int, int>> v;
    for(auto &x : mp) {
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);
    return v;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, m; i < N; i++) {
        cin >> m;
        freq[m]++;
    }
    auto v = sort(freq);
    int high_val = v[v.size()-1].first, high_freq = v[v.size()-1].second;
    int max_val = -1;
    for(int j = 0; j <= high_freq; j++) {
        for(int i = v.size()-2; i >= 0; i--) {
            if(high_freq-j == v[i].second) {
                max_val = max(max_val, abs(high_val - v[i].first));
            }
            if(max_val == -1) {
                break;
            }
        }
        if(max_val != -1) {
            break;
        }
    }
    cout << max_val << "\n";
    return 0;
}
