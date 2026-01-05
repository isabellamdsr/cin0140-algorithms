#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int min_coin(int x, int n, vector<int> &C, vector<int> &F) {
    for (int sum = 1; sum <= x; sum++) {
        for (int i = 0; i < n; i++) {
            if (sum - C[i] >= 0 && F[sum - C[i]] != INT_MAX) {
                F[sum] = min(F[sum], F[sum - C[i]] + 1);
            }
        }
    }

    if (F[x] == INT_MAX) return -1;
    else return F[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> C(n);
    vector<int> F(x+1, INT_MAX);
    F[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    int num_coins = min_coin(x, n, C, F);
    cout << num_coins;
}
