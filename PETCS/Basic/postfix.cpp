#include <bits/stdc++.h>
using namespace std;

stack<double> st;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    string s;
    while(cin >> s) {
        if(s == "*") {
            double s = st.top(); st.pop();
            double f = st.top(); st.pop();
            st.push(f*s);
        } else if(s == "/") {
            double s = st.top(); st.pop();
            double f = st.top(); st.pop();
            st.push(f/s);
        } else if(s == "+") {
            double s = st.top(); st.pop();
            double f = st.top(); st.pop();
            st.push(f+s);
        } else if(s == "-") {
            double s = st.top(); st.pop();
            double f = st.top(); st.pop();
            st.push(f-s);
        } else if(s == "%") {
            double s = st.top(); st.pop();
            double f = st.top(); st.pop();
            st.push(int(f)%int(s));
        } else if(s == "^") {
            double s = st.top(); st.pop();
            double f = st.top(); st.pop();
            st.push(pow(f, s));
        } else {
            st.push(stod(s));
        }
    }
    cout << fixed << setprecision(1) << st.top() << "\n";
    return 0;
}
