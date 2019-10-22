#pragma GCC optimize "O2"

int setbits(unsigned long long N) {
    asm volatile ("POPCNT %1, %0;":"=r"(N):"r"(N):);
    return N;
}
