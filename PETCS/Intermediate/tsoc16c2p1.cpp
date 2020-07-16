#include <bits/stdc++.h>
using namespace std;
int N; string str;
vector<char> bufs;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> str;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'X') {
            int sz = 0;
            while(str[i] == 'X') {
                sz++; i++;
            }
            bufs[bufs.size()-sz] = str[i];
        } else {
            bufs.push_back(str[i]);
        }
    }
    for(int i = 0; i < N; i++) {
        cin >> str;
        char c = bufs[i];
        cout << "Dear " << str;
        if (c == 'A'){
            cout << ", beloved artist, I would love to have you at my party. Come to my crib on April 20th.\n";
        }else if (c == 'O'){
            cout << ", beloved occasion enthusiast, come to my crib to celebrate this very special day.\n";
        }else if (c == 'R'){
            cout << ", April 20th is happening again this year. Don't miss out.\n";
        }
    }
    return 0;
}
