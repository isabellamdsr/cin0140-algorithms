#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
};

void create_graph(Graph &g, int n) {
    g.V = n;
    g.adj.resize(n+1, vector<int>(n+1, INT_MAX));
    
    for (int i = 1; i <= n; i++) {
        g.adj[i][i] = 0; // dist de um nó para si mesmo
    }
}

void add_edge(Graph &g, int u, int v, int weight) {
    g.adj[u][v] = min(g.adj[u][v], weight);
}

void floyd_warshall(Graph &g) {
    int n = g.V;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g.adj[i][k] != INT_MAX && g.adj[k][j] != INT_MAX && g.adj[i][j] > g.adj[i][k] + g.adj[k][j]) {
                    g.adj[i][j] = g.adj[i][k] + g.adj[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    
    for (int i = 1; i <= c; i++) {
        int cells, exit, T, M;
        cin >> cells >> exit >> T >> M;
        
        Graph g;
        create_graph(g, cells);
        
        for (int j = 0; j < M; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(g, u, v, w);
        }
        
        floyd_warshall(g);
        
        int qtd = 0;
        for (int k = 1; k <= cells; k++) {
            if (g.adj[k][exit] <= T) qtd++;
        }
        
        cout << qtd << "\n";
        if (i < c) cout << "\n";
    }
}