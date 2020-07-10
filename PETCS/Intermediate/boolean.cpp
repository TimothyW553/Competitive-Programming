#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; int cnt = 0;
    bool flag = false;
    while(cin >> s) {
        if(s == "not") {
            cnt++;
        } else if(s == "True") {
            flag = true;
        }
    }
    s = "True";
    if(cnt % 2 == 0 and !flag) {
        s = "False";
    } else if(cnt % 2 == 1 and flag) {
        s = "False";
    }
    cout << s << "\n";
    return 0;
}
