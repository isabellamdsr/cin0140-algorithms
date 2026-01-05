#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int MFKnapsack(int i, int j, vector<int> &w, vector<int> &v, vector<vector<int>> &F) {
    if (i == 0) return 0;
    if (F[i][j] < 0) {
        int value;
        
        if (j < w[i-1]) value = MFKnapsack(i-1, j, w, v, F);
        else {
            int a = MFKnapsack(i-1, j, w, v, F);
            int b = v[i-1] + MFKnapsack(i-1, j-w[i-1], w, v, F);
            value = max(a, b);
        }
        F[i][j] = value;
    }
    return F[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    vector<string> name(n);
    vector<int> w(n);
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> name[i] >> w[i] >> v[i];

    vector<vector<int>> F(n+1, vector<int>(W+1, -1));

    int maxFeliz = MFKnapsack(n, W, w, v, F);

    vector<string> toys;
    int j = W;

    for (int i = n; i > 0; i--) {
        int skip = MFKnapsack(i - 1, j, w, v, F);
        if (j >= w[i-1]) {
            int t = v[i-1] + MFKnapsack(i-1, j - w[i-1], w, v, F);
            if (t > skip) {
                toys.push_back(name[i-1]);
                j -= w[i-1];
            }
        }
    }

    reverse(toys.begin(), toys.end());

    cout << maxFeliz << ": ";
    for (int i = 0; i < toys.size(); i++) {
        cout << toys[i];
        if (i + 1 < toys.size()) cout << ", ";
    }
    cout << "\n";
}