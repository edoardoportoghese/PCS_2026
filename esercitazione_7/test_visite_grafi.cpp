#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"

using namespace std;

int main() {

   
    // GRAFO PER DFS / BFS //
  
    unidirected_graph<int> g;

    g.add_edge({0, 1});
    g.add_edge({0, 2});
    g.add_edge({1, 3});
    g.add_edge({2, 3});
    g.add_edge({3, 4});

    cout << " BFS " << endl;
    Queue<int> q;
    auto bfs_tree = graph_visit(g, 0, q);

    for (auto e : bfs_tree.all_edges())
        cout << e << endl;

    cout << " DFS (iterativa)" << endl;
    Stack<int> s;
    auto dfs_tree = graph_visit(g, 0, s);

    for (auto e : dfs_tree.all_edges())
        cout << e << endl;

    cout << "DFS (ricorsiva)" << endl;
    auto rec_tree = recursive_dfs(g, 0);

    for (auto e : rec_tree.all_edges())
        cout << e << endl;


    // GRAFO PER DIJKSTRA //

    vector<vector<pair<int, double>>> adj(5);

    const double INF =
        numeric_limits<double>::infinity();

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 5});

    adj[1].push_back({2, 1});
    adj[1].push_back({3, 2});

    adj[2].push_back({3, 3});
    adj[3].push_back({4, 1});

    vector<int> pred;

    cout << "DIJKSTRA" << endl;

    vector<double> dist = dijkstra(adj, 0, pred);

    for (int i = 0; i < dist.size(); i++) {
        cout << "Nodo " << i
             << " dist = "
             << dist[i]
             << " pred = "
             << pred[i]
             << endl;
    }


    // CAMMINO 0 -> 4 //
  
   

    cout << "CAMMINO 0 -> 4 " << endl;

    int target = 4;
    vector<int> path;

    while (target != -1) {
        path.push_back(target);
        target = pred[target];
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i) cout << " -> ";
    }

    cout << endl;

    return 0;
}