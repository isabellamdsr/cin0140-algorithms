#include <iostream>
#include <vector>
    
using namespace std;
    
int partition(vector<int> &v, int l, int r) {
    int p = v[l];
    int i = l;
    int j = r + 1;
    
    while (i < j) {
        do {
            i++;
        } while (v[i] < p && i < r);
    
        do {
            j--;
        } while (v[j] > p);
    
        swap(v[i], v[j]);
    }
    swap(v[i], v[j]);
    swap(v[l], v[j]);
    return j;
}
    
void quicksort(vector<int> &v, int l, int r) {
    int qtdl = 0;
    int qtdr = 0;
    
    if (l < r) {
        int s = partition(v, l, r);
        
        for (int i = s-1; i >= l; i--) {
            qtdl++;
        }
    
        for (int j = s+1; j <= r; j++) {
            qtdr++;
        }
    
        cout << qtdl << " " << qtdr << "\n";
    
        quicksort(v, l, s-1);
    
        quicksort(v, s+1, r);
    
    }
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    quicksort(v, 0, N-1);
}