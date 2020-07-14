#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
double mean, median, mode;
int N, tot, a[MAX];
map<int, double> freq;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        freq[a[i]]++;
        mean += a[i];
    }
    mean /= (1.0*N);
    sort(a, a+N);
    if(N % 2 == 0) {
        median = (a[N/2]+a[N/2-1])/2.0;
    } else {
        median = a[N/2];
    }
    double max_freq = -1;
    for(auto &x : freq) {
        max_freq = max(max_freq, x.second);
    }
    double sum = 0, num = 0;
    for(auto &x : freq) {
        if(x.second == max_freq) {
            sum += x.first;
            num++;
        }
    }
    if(sum != max_freq) {
        mode = sum / num;
    }
    double avg = min(mean, min(median, mode));
    tot = upper_bound(a, a+N, avg)-a;
    cout << tot << "\n";
    return 0;
}
