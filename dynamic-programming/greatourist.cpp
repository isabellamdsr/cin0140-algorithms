#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll backtrack(int i, ll sum, ll k, vector<ll> &A, vector<pair<int,int>> &F, vector<int> &U) {
    if (sum > k) return 0;

    if (i == A.size()) {
        for (int a = 0; a < F.size(); a++) {
            int x = F[a].first;
            int y = F[a].second;

            if (U[x] && U[y]) return 0;
        }
        return 1;
    }

    ll total = 0;
    U[i] = 0;
    total += backtrack(i+1, sum, k, A, F, U);

    U[i] = 1;
    total += backtrack(i+1, sum + A[i], k, A, F, U);

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll limit;
    cin >> n >> m >> limit;

    vector<ll> A(n);
    vector<int> used(n, 0);
    vector<pair<int,int>> fpairs(m); // forbidden pairs

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < m; i++) {
        cin >> fpairs[i].first >> fpairs[i].second;
        fpairs[i].first--;
        fpairs[i].second--;
    }

    ll qtd = backtrack(0, 0, limit, A, fpairs, used);
    cout << qtd;
}
