#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vis;

void init() {
    vis.push_back({0, -1});
    vis.push_back({0, -2});
    vis.push_back({0, -3});
    vis.push_back({1, -3});
    vis.push_back({2, -3});
    vis.push_back({3, -3});
    vis.push_back({3, -4});
    vis.push_back({3, -5});
    vis.push_back({4, -5});
    vis.push_back({5, -5});
    vis.push_back({5, -4});
    vis.push_back({5, -3});
    vis.push_back({6, -3});
    vis.push_back({7, -3});
    vis.push_back({7, -4});
    vis.push_back({7, -5});
    vis.push_back({7, -6});
    vis.push_back({7, -7});
    vis.push_back({6, -7});
    vis.push_back({5, -7});
    vis.push_back({4, -7});
    vis.push_back({3, -7});
    vis.push_back({2, -7});
    vis.push_back({1, -7});
    vis.push_back({0, -7});
    vis.push_back({-1, -7});
    vis.push_back({-1, -6});
    vis.push_back({-1, -5});
}

int x = -1, y = -5;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    char dir;
    int n;
    init();
    while(1) {
        bool danger = false;
        cin >> dir >> n;
        switch(dir) {
            case 'u':
                for(int i = 0; i < n; i++) {
                    y += 1;
                    for(auto &pr : vis) {
                        if(pr.first == x and pr.second == y) {
                            danger = true;
                        }
                    }
                    vis.push_back({x, y});
                }
                break;
            case 'd':
                for(int i = 0; i < n; i++) {
                    y -= 1;
                    for(auto &pr : vis) {
                        if(pr.first == x and pr.second == y) {
                            danger = true;
                        }
                    }
                    vis.push_back({x, y});
                }
                break;
            case 'l':
                for(int i = 0; i < n; i++) {
                    x -= 1;
                    for(auto &pr : vis) {
                        if(pr.first == x and pr.second == y) {
                            danger = true;
                        }
                    }
                    vis.push_back({x, y});
                }
                break;
            case 'r':
                for(int i = 0; i < n; i++) {
                    x += 1;
                    for(auto &pr : vis) {
                        if(pr.first == x and pr.second == y) {
                            danger = true;
                        }
                    }
                    vis.push_back({x, y});
                }
                break;
            case 'q':
                return 0;
        }
        if(danger) {
            cout << x << " " << y << " DANGER" << "\n";
            return 0;
        } else {
            cout << x << " " << y << " safe" << "\n";
        }
    }
    return 0;
}
