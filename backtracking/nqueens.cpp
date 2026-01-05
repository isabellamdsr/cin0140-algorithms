#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool valid(vector<vector<int>> &M, int l, int i) {
    for (int x = 0; x < l; x++) {
        if (M[x][i] == 1) return false;
    }

    for (int x = l, y = i; x >= 0 && y >= 0; x--, y--) {
        if (M[x][y] == 1) return false;
    }

    for (int x = l, y = i; x >= 0 && y < M.size(); x--, y++) {
        if (M[x][y] == 1) return false;
    }

    return true;
}

int qtd = 0;
bool n_Queens(int l, vector<vector<int>> &M) {
    if (l == M.size()) {
        qtd++;
        return false;
    }

    else {
        for (int i = 0; i < M.size(); i++) {
            if (valid(M,l,i)) {
                M[l][i] = 1;
                if(n_Queens(l+1, M)) return false;
                M[l][i] = 0;
            }
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> M;
    M.resize(n, vector<int>(n, 0));

    n_Queens(0, M);

    cout << qtd;
}