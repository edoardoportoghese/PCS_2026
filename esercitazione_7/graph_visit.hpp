#include "unidirected_graph.hpp"
#include <map>
#include "stack.hpp"
#include "queue.hpp"

template<typename T,typename Structure>
unidirected_graph<T> graph_visit(
    const unidirected_graph<T>& graph,
    const T& source,
    Structure& structure
) {

    // albero di visita
    unidirected_graph<T> tree;

    // nodi raggiunti
    std::map<T, bool> reached;

    // il source è visitato
    reached[source] = true;

    // inserisce source
    structure.put(source);

    // visita
    while (!structure.empty()) {

        // nodo corrente
        T current = structure.get();

        // vicini
        std::set<T> neighs =
            graph.neighbours(current);

        // scorre i vicini
        for (const T& next : neighs) {

            // non visitato
            if (!reached[next]) {

                reached[next] = true;

                // crea il nodo/arco
                unidirected_edge<T> edge(
                    current,
                    next
                );

                // aggiunge all'albero
                tree.add_edge(edge);

                // inserisce nella struttura
                structure.put(next);
            }
        }
    }

    return tree;
}