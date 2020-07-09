#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, double> a, pair<string, double> b) { return a.second < b.second; }

int P, T;
vector<pair<string, double>> presents;
vector<pair<string, double>> teachers;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> P >> T; cin.ignore();
    double price;
    for(int i = 0; i < P; i++) {
        string present; getline(cin, present);
        cin >> price; cin.ignore();
        presents.push_back({present, price});
    }
    double rating;
    for(int i = 0; i < T; i++) {
        string teacher; getline(cin, teacher);
        cin >> rating; cin.ignore();
        teachers.push_back({teacher, rating});
    }
    sort(presents.begin(), presents.end(), cmp);
    sort(teachers.begin(), teachers.end(), cmp);
    for(int i = 0; i < T; i++) {
        cout << teachers[i].first << " will get a " << presents[i].first << "\n";
    }
    return 0;
}
