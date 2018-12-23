#include <bits/stdc++.h>
using namespace std;

string str = "#";
string spaces = "";
void staircase(int n) {
    for(int i = 0; i < n-1; i++)
        spaces += " "; // creates n-1 spaces
	
    for(int i = 0; i < n; i++) {
        cout << spaces; // outputs all n-1 spaces in the first line
        cout << str; // outputs 1 #
        str += "#"; // adds 1 # at the end of the str string
        cout << "\n"; // new line
        spaces.pop_back(); // removes the last character from the end of the spaces string
    }
}

int main() {
    int n;
    cin >> n;
    staircase(n);
    return 0;
}
