#include <iostream>
#include <vector>
using namespace std;

int binsearch(vector<int> &A, int l, int r, int K) {
    int qtd = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (A[m] <= K) {
            qtd = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return qtd + 1;
}