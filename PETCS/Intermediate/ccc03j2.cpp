#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    while(1) {
        scanf("%d", &N);
        if(N == 0) {
            break;
        }
        for(int i = sqrt(N); i; i--) {
            if(N % i == 0) {
                printf("Minimum perimeter is %d with dimensions %d x %d\n", 2*(i+N/i), i, N/i);
                break;
            }
        }
    }
    return 0;
}
