#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int,int>>> adj;
};

void add_edge(Graph &G, int u, int v, int w) {
    G.adj[u].push_back({v, w});
    G.adj[v].push_back({u, w});
}

void prim(Graph &G, vector<int> D, vector<int> P) {
    vector<bool> visited(G.V, false);
    priority_queue<pair<int,int>> heap;

    for (int i = 0; i < G.V; i++) {
        D[i] = INT_MAX;
        P[i] = -1;
    }

    heap.push({0,0});
    D[0] = 0;

    for (int i = 0; i < G.V; i++) {
        int w;
        int v = -1;
        while (!heap.empty()) {
            v = heap.top().first;
            w = heap.top().second;
            heap.pop();

            if (!visited[v]) break;
        }

        if (v == -1) break;
        visited[v] = true;
        P[v] = w;

        while (w < G.V) {
            if (!visited[w] && D[w] > G.adj[v][w].second) {
                D[w] = G.adj[v][w].second;
                heap.push({-D[w], w});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, o;
    cin >> c >> o;
    Graph G;

    for (int x = 0; x < o;  x++) {
        int i, j, p;
        cin >> i >> j >> p;

        add_edge(G, i, j, p);
    }

    vector<int> P, D;
    prim(G, D, P);

    int min = 0;
    for (int y = 0; y < c; y++) {
        if (D[y] != INT_MAX) {
            min += D[y];
        }
    cout << min;
    }   
}