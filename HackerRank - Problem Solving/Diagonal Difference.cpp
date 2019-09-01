#include <bits/stdc++.h>
using namespace std;

int sumOfDiagonal1 = 0, sumOfDiagonal2 = 0;
int arr[100][100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0, j = 0; i < n && j < n; i++, j++)
        sumOfDiagonal1 += arr[i][j];

    for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--)
        sumOfDiagonal2 += arr[i][j];

    cout << abs(sumOfDiagonal1 - sumOfDiagonal2) << "\n";
}
