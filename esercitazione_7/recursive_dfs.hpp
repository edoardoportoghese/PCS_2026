//includere unidirected_graph.hpp se serve//
#include <set>

template<typename T>
void dfs_visit(
    const unidirected_graph<T>& graph,
    const T& node,
    std::set<T>& reached,
    unidirected_graph<T>& tree
) {
    reached.insert(node);

    for (const T& next : graph.neighbours(node)) {

        if (reached.find(next) == reached.end()) {

            tree.add_edge(
                unidirected_edge<T>(node, next)
            );

            dfs_visit(graph, next, reached, tree);
        }
    }
}

template<typename T>
unidirected_graph<T> recursive_dfs(
    const unidirected_graph<T>& graph,
    const T& source
) {

    unidirected_graph<T> tree;
    std::set<T> reached;

    dfs_visit(graph, source, reached, tree);

    return tree;
}