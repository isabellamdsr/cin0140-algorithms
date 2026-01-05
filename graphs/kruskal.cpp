#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
    
    Graph(int n) {
        V = n;
        adj.resize(n);
    }

    void add_edge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
};

struct DisjointSet {
    vector<int> R;
    
    DisjointSet(int n) {
        R.resize(n);
        for (int i = 0; i < n; i++) {
            R[i] = i;
        }
    }

    int find(int curr) {
        return R[curr];
    }
    
    void union_sets(int a, int b) {
        int rt1 = find(a);
        int rt2 = find(b);
        if (rt1 != rt2) {
            for (int i = 0; i < R.size(); i++) {
                if (R[i] == rt2) R[i] = rt1;
            }
        }
    }
};

void kruskal(Graph &G, Graph &G1) {
    vector<tuple<int, int, int>> H;
    
    for (int i = 0; i < G.V; i++) {
        for (int j = 0; j < G.adj[i].size(); j++) {
            int w = G.adj[i][j].first;
            int weight = G.adj[i][j].second;
            if (i < w) { 
                H.push_back({weight, i, w});
            }
        }
    }
    sort(H.begin(), H.end());
    DisjointSet ds(G.V);
    int numMST = G.V;
    
    int ind = 0;
    while (numMST > 1 && ind < H.size()) {
        int weight = get<0>(H[ind]);
        int u = get<1>(H[ind]);
        int v = get<2>(H[ind]);
        ind++;
        
        if (ds.find(u) != ds.find(v)) {
            ds.union_sets(u, v);
            G1.add_edge(u, v, weight);
            numMST--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        Graph g(n), g1(n);

        vector<tuple<int, int, int>> edges; // comparar com o grafo original dps do kruskal
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g.add_edge(u, v, w);
            edges.push_back({u, v, w});
        }
        
        kruskal(g, g1);
        
        vector<bool> mst_edges(m, false);
        for (int u = 0; u < g1.V; u++) {
            for (int j = 0; j < g1.adj[u].size(); j++) {
                int v = g1.adj[u][j].first;
                int w = g1.adj[u][j].second;
                
                for (int e = 0; e < edges.size(); e++) {
                    int u2 = get<0>(edges[e]);
                    int v2 = get<1>(edges[e]);
                    int w2 = get<2>(edges[e]);
                    
                    if (w == w2 && ((u == u2 && v == v2) || (u == v2 && v == u2))) {
                        mst_edges[e] = true;
                        break;
                    }
                }
            }
        }
        
        vector<int> heaviest;
        for (int i = 0; i < m; i++) {
            if (!mst_edges[i]) {
                heaviest.push_back(get<2>(edges[i]));
            }
        }
        
        if (heaviest.empty()) cout << "forest\n";
        else {
            sort(heaviest.begin(), heaviest.end());
            for (int i = 0; i < heaviest.size(); i++) {
                if (i > 0) cout << " ";
                cout << heaviest[i];
            }
            cout << "\n";
        }
    }
}