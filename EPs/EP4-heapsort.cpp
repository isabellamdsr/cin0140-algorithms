// time limit no cf - otimizar depois

#include <iostream>
#include<vector>
 
using namespace std;
 
void heapify(vector<int> &H, int k, int n) {
    bool heap = false;
    int v = H[k];
    int j;
 
    while (!heap && 2*k <= n) {
        j = 2*k;
 
        if (j < n)
            if (H[j] > H[j+1]) j++;
        
        if (v <= H[j]) heap = true;
 
        else {
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
}
 
void heapBottomUp(vector<int> &H, int n) {
    for (int i = n/2; i >= 1; i--) {
        heapify(H, i, n);
    }
}
 
void heapsort(vector<int> &H) {
    int n = H.size() - 1;
    heapBottomUp(H,n);
 
    for (int i = n; i >= 2; i--) {
        swap(H[1],H[i]);
        heapify(H, 1, i-1);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    bool win = false;
    cin >> N;
 
    vector<int> H(N+1);
    H[0] = -1;
 
    for (int i = 1; i < N+1; i++) {
        cin >> H[i];
    }
 
    heapsort(H);
 
    if (H[N] != H[N-1]) {
        cout << H[N];
        win = true;
        }
 
    else {
        for (int i = N; i>=1; i--) {
            if (i != N && H[i] != H[i+1] && H[i] != H[i-1]) {
                cout << H[i];
                win = true;
                break;
            }
        }
    }
    
    if (!win) cout << -1;
}