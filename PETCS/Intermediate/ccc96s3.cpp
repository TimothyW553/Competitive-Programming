#include <bits/stdc++.h>
using namespace std;
int N;
void out(int s, int n, string output){
    if(!s)
        cout<<output<<endl;
    else if(!n)
        out(s-1,n,output+"0");
    else{
        out(s-1,n-1,output+"1");
        if(s != n){
            out(s-1,n,output+"0");
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 0, n, k; i < N; i++) {
        cin >> n >> k;
        cout << "The bit patterns are " << "\n";
        out(n, k, "");
    }
    return 0;
}
