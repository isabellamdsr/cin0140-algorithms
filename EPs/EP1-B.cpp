    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;
     
    void merge(vector<pair<string,int>> &v, int l, int r, int N) {
        vector<pair<string,int>> temp(N);
     
        for (int i = l; i <= r; i++) {
            temp[i].first = v[i].first;
            temp[i].second = v[i].second;
        }
     
        int m = (l+r)/2;
        int i1 = l;
        int i2 = m + 1;
     
        for (int curr = l; curr <= r; curr++) {
            if (i1 == m + 1) {
                v[curr] = temp[i2++];
            } else if (i2 > r) {
                v[curr] = temp[i1++];
            } else if (temp[i1].first < temp[i2].first or (temp[i1].first == temp[i2].first and temp[i1].second <= temp[i2].second)) {
                v[curr] = temp[i1++];
            } else
                v[curr] = temp[i2++];
        }
    }
     
    void mergesort(vector<pair<string,int>> &v, int l, int r, int N) {
        if (l<r) {
            int m = (l+r)/2;
            mergesort(v, l, m, N);
            mergesort(v, m+1, r, N);
            merge(v, l, r, N);
        }
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     
        int N;
        cin >> N;
     
        vector<pair<string,int>> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i].first >> v[i].second;
        }
     
        mergesort(v, 0, N-1, N);
     
        for (int i = 0; i < N; i++) {
            cout << v[i].first << " " << v[i].second << "\n";
        }
    }