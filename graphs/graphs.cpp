#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    int v;
    vector<vector<int>> adj;
    vector<vector<int>> w;
    vector<string> mark;

public:
    Graph(int n) {
        v = n;
        adj.resize(n);
        w.resize(n, vector<int>(n, 0));
        mark.resize(n, "UNVISITED");
    }

    int n() {
        return v;
    }

    int e() {
        int edges = 0;
        for (int i = 0; i < v; ++i) {
            edges += adj[i].size();
        }
        return edges;
    }

    void setMark(int v, string state) {
        mark[v] = state;
    }

    string getMark(int v) {
        return mark[v];
    }

    void setEdge(int i, int j, int weight) {
        adj[i].push_back(j);
        w[i][j] = weight;
    }

    void printGraph() {
        for (int i = 0; i < v; ++i) {
            cout << "Vértice " << i << ": ";
            for (size_t j = 0; j < adj[i].size(); ++j) {
                cout << adj[i][j] << "(" << w[i][adj[i][j]] << ") ";
            }
            cout << endl;
        }
    }

    void traverse(int v) {
        setMark(v, "VISITED");

        for (int w : adj[v]) {
            if (getMark(w) == "UNVISITED") traverse(w);
        }
    }

    void graphTraverse() {
        for (int i = 0; i < v; ++i) {
            if (getMark(i) == "UNVISITED") traverse(i);
        }
    }
};