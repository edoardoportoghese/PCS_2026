#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<double> dijkstra(
    const vector<vector<pair<int, double>>>& adj,
    int source,
    vector<int>& pred
) {
    const double INF =
        numeric_limits<double>::infinity();

    int n = adj.size();

    vector<double> dist(n, INF);
    pred = vector<int>(n, -1);

    priority_queue<
        pair<double, int>,
        vector<pair<double, int>>,
        greater<pair<double, int>>
    > pq;

    dist[source] = 0;
    pred[source] = source;

    pq.push({0, source});

    while (!pq.empty()) {

        auto [d, u_i] = pq.top();
        pq.pop();

        if (d != dist[u_i])
            continue;

        // esploro SOLO archi reali
        for (auto [v_i, w_uv] : adj[u_i]) {

            if (dist[v_i] > dist[u_i] + w_uv) {

                dist[v_i] = dist[u_i] + w_uv;
                pred[v_i] = u_i;

                pq.push({dist[v_i], v_i});
            }
        }
    }

    return dist;
}