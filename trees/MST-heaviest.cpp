#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int, int>>> adj; // (vizinho, peso)
};

void create_graph(Graph &g, int n) {
    g.V = n;
    g.adj.resize(n);
}

void add_edge(Graph &g, int u, int v, int weight) {
    g.adj[u].push_back({v, weight});
    g.adj[v].push_back({u, weight});
}

int prim(Graph &g, vector<int> &D, vector<int> &P) {
    priority_queue<pair<int, int>> heap; // (-peso, vértice)
    vector<bool> visited(g.V, false);

    for (int i = 0; i < g.V; i++) {
        D[i] = INT_MAX;
        P[i] = -1;
    }
    
    D[0] = 0;
    heap.push({0, 0});

    int num_visited = 0;
    
    for (int i = 0; i < g.V; i++) {
        int v = -1;
        while (!heap.empty()) {
            int atual = heap.top().second;
            heap.pop();
            if (!visited[atual]) {
                v = atual;
                break;
            }
        }
        if (v == -1) break;
        visited[v] = true;
        num_visited++;
        
        for (int j = 0; j < g.adj[v].size(); j++) {
            int vv = g.adj[v][j].first;
            int weight = g.adj[v][j].second;
            
            if (!visited[vv] && weight < D[vv]) {
                D[vv] = weight;
                P[vv] = v;
                heap.push({-D[vv], vv});
            }
        }
    }
    return num_visited;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        Graph g;
        create_graph(g, n);

        for (int x = 0; x < m; x++) {
            int i, j, p;
            cin >> i >> j >> p;
            add_edge(g, i, j, p);
        }

        vector<int> D(n, INT_MAX);
        vector<int> P(n, -1);
        
        int visited = prim(g, D, P); 

        if (visited != n) cout << "IMPOSSIBLE" << "\n";
        else {
            int maior = 0;
            for (int y = 0; y < n; y++) {
                if (D[y] > maior)  maior = D[y];
                }
            cout << maior << "\n";
            }
        }
    }