// bottom-up --> elements known beforehand

#include <iostream> 
#include <vector>

using namespace std;

void heapify(vector <int> &H, int k, int n) {
    int v = H[k];
    bool heap = false;
    int j;

    while (!heap && 2*k <= n) {
        j = k*2;

        if (j < n) // has two children
            if (H[j] > H[j+1]) j++; // min heap
        
        if (v <= H[j])
            heap = true;
        
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
    heapBottomUp(H, n);

    for (int i = n; i >= 2; i--) {
        swap(H[1], H[i]);  // exchanges the root's key w/ the last key k
        heapify(H, 1, i - 1); // decrease heap size
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> H(N+1);
    H[0] = -1;

    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    heapsort(H);

    for (int i = N; i >= 1; i--) {
        if (H[N] != H[N-1]) {
            cout << H[N];
            break;
        }
        else if (i != N && H[i] != H[i-1] && H[i] != H[i+1]) {
            cout << H[i];
            break;
        }
        else
            if (i == 1) cout << -1;
    }
}