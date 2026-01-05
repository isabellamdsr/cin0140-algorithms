#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long backtrack(int i, long long sum, long long k, vector<long long> &A) {
    if (sum > k) return 0;

    if (i == A.size()) {
        if (sum == k) return 1;
        else return 0;
    }

    long long total = 0;
    total += backtrack(i+1, sum, k, A);
    total += backtrack(i+1, sum + A[i], k, A);

    return total;
}

int main() {
   ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    long long total = backtrack(0, 0, k, A);
    cout << total;
}