#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Graph {
    int v;
    vector<vector<int>> adj; 
    vector<string> mark;

    Graph(int n) {
        v = n;
        adj.resize(n);
        mark.resize(n, "UNVISITED");
    }

    void setMark(int v, string state) {
        mark[v] = state;
    }

    string getMark(int v) {
        return mark[v];
    }

    void addEdge(int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    void DFS(int v) {
        setMark(v, "VISITED");
        for (int w : adj[v]) {
            if (getMark(w) == "UNVISITED") {
                DFS(w);
            }
        }
    }

    int qtdConexos() {
        int conexos = 0;
        for (int i = 0; i < v; i++) {
            if (getMark(i) == "UNVISITED") {
                conexos++;
                DFS(i);
            }
        }
        return conexos;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int vertices, arestas;
        cin >> vertices >> arestas;

        Graph g(vertices);

        for (int i = 0; i < arestas; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }

        cout << g.qtdConexos() << "\n";
    }
}
