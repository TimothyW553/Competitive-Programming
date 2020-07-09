#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    int a = 0, b = 0;
    char x, y;
    while(1) {
        int cmd; cin >> cmd;
        switch(cmd) {
            case 1:
                cin >> x;
                int n; cin >> n;
                if(x == 'A') { 
                    a = n;
                } else {
                    b = n;
                }
                break;
            case 2:
                char x; cin >> x;
                if(x == 'A') {
                    cout << a << "\n";
                } else {
                    cout << b  << "\n";
                }
                break;
            case 3:
                cin >> x >> y;
                if(x == 'A' and y == 'B') {
                    a = a+b;
                } else if(x == 'B' and y == 'A') {
                    b = b+a;
                } else if(x == 'A' and y == 'A') {
                    a = a+a;
                } else if(x == 'B' and y == 'B') {
                    b = b+b;
                }
                break;
            case 4: 
                cin >> x >> y;
                if(x == 'A' and y == 'B') {
                    a = a*b;
                } else if(x == 'B' and y == 'A') {
                    b = b*a;
                } else if(x == 'A' and y == 'A') {
                    a = a*a;
                } else if(x == 'B' and y == 'B') {
                    b = b*b;
                }
                break;
            case 5:
                cin >> x >> y;
                if(x == 'A' and y == 'B') {
                    a = a-b;
                } else if(x == 'B' and y == 'A') {
                    b = b-a;
                } else if(x == 'A' and y == 'A') {
                    a = a-a;
                } else if(x == 'B' and y == 'B') {
                    b = b-b;
                }
                break;
            case 6:
                cin >> x >> y;
                if(x == 'A' and y == 'B') {
                    a = int((double)(a)/(double)(b));
                } else if(x == 'B' and y == 'A') {
                    b = int((double)(b)/(double)(a));
                } else if(x == 'A' and y == 'A') {
                    a = int((double)(a)/(double)(a));
                } else if(x == 'B' and y == 'B') {
                    b = int((double)(b)/(double)(b));
                }
                break;
            case 7:
                return 0;
        }
    }
    return 0;
}
