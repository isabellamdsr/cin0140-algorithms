#include <iostream>
#include <vector>
#include <string>
    
using namespace std;
    
int binsearch(vector<string> &A, int l, int r, string K) {
    if (l<=r) {
        int m = (l+r)/2;
    
        if (K == A[m])
            return 1;
        else if (K < A[m])
            return binsearch(A, l, m-1, K);
        else
            return binsearch(A, m+1, r, K);
    }
    else
        return 0;
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int words, tries;
    int qtd = 0;
    cin >> words;
    string word;
    vector<string> A(words);
    
    
    for (int i = 0; i < words; i++) {
        cin >> A[i];
    }
    
    cin >> tries;
    for (int i = 0; i < tries; i++) {
        cin >> word;
        qtd += binsearch(A, 0, words-1, word);
    }
    
    cout << qtd;
}