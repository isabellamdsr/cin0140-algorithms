#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll playlist_row(int K, int N, vector<ll> &A, vector<ll> &F) {
    for (int i = 1; i <= N; i++) {
        ll choose = A[i];

        if (i - K >= 0) choose += F[i-K];

        ll skip = F[i - 1];
        F[i] = max(skip, choose);
    }

    return F[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<ll> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<ll> F(N + 1, 0);
    F[0] = 0;

    cout << playlist_row(K, N, A, F);
}