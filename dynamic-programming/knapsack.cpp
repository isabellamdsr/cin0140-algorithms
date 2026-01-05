#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> name;
vector<int> w, v;
vector<vector<int>> F;

int MFKnapsack(int i, int j) {
    if (i == 0) return 0;
    if (F[i][j] < 0) {
        int value;
        
        if (j < w[i - 1]) value = MFKnapsack(i-1, j);
        else {
            int a = MFKnapsack(i - 1, j);
            int b = v[i - 1] + MFKnapsack(i - 1, j - w[i - 1]);
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

    name.resize(n);
    w.resize(n);
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> name[i] >> w[i] >> v[i];

    F.assign(n + 1, vector<int>(W + 1, -1));

    int maxHappy = MFKnapsack(n, W);

    vector<string> chosen;
    int j = W;

    for (int i = n; i > 0; i--) {
        int skip = MFKnapsack(i - 1, j);
        if (j >= w[i - 1]) {
            int take = v[i - 1] + MFKnapsack(i - 1, j - w[i - 1]);
            if (take > skip) {
                chosen.push_back(name[i - 1]);
                j -= w[i - 1];
                continue;
            }
        }
    }

    reverse(chosen.begin(), chosen.end());

    cout << maxHappy << ": ";
    for (int i = 0; i < chosen.size(); i++) {
        cout << chosen[i];
        if (i + 1 < chosen.size()) cout << ", ";
    }
    cout << "\n";
}