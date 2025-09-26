#include <iostream>
#include <vector>
#include <algorithm>
    
using namespace std;
    
int binsearch(vector<int> &A, int l, int r, int K) {
    int maior, menor;
    while (l<=r) {
        int m = (l+r)/2;
    
        if (K == A[m])
            return A[m];
        else if (K < A[m])
            r = (m-1);
        else
            l = (m+1);
        }
    
    menor = A[l-1];
    maior = A[r+1];
    
    if (abs(maior-K) < abs(menor-K))
        return maior;
    else
        return menor;
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q, num;
    cin >> n;
    vector<int> lista(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }
    
    sort(lista.begin(), lista.end());
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> num;
        cout << binsearch(lista, 0, n-1, num) << "\n";
    }
}