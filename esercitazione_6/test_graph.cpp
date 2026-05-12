#include <iostream>

#include "unidirected_graph.hpp"

int main() {

    // crea un grafo
    unidirected_graph<int> g;

    // aggiunge archi
    g.add_edge({1, 2});
    g.add_edge({2, 3});
    g.add_edge({1, 3});
    g.add_edge({4, 1});

    // ----------------------------
    // TEST all_nodes()
    // ----------------------------

    std::cout << "Nodi del grafo:\n";

    for (const auto& n : g.all_nodes())
        std::cout << n << " ";

    std::cout << "\n\n";

    // ----------------------------
    // TEST all_edges()
    // ----------------------------

    std::cout << "Archi del grafo:\n";

    for (const auto& e : g.all_edges())
        std::cout << e << "\n";

    std::cout << "\n";

    // ----------------------------
    // TEST neighbours()
    // ----------------------------

    std::cout << "Vicini del nodo 1:\n";

    for (const auto& n : g.neighbours(1))
        std::cout << n << " ";

    std::cout << "\n\n";

    // ----------------------------
    // TEST edge_number()
    // ----------------------------

    unidirected_edge<int> e1(1, 3);

    std::cout << "Indice arco "
              << e1
              << ": ";

    std::cout << g.edge_number(e1)
              << "\n\n";

    // ----------------------------
    // TEST edge_at()
    // ----------------------------

    std::cout << "Arco in posizione 2:\n";

    std::cout << g.edge_at(2)
              << "\n\n";

    // ----------------------------
    // TEST operator-
    // ----------------------------

    unidirected_graph<int> g2;

    g2.add_edge({1, 2});
    g2.add_edge({2, 3});

    // differenza tra grafi
    auto diff = g - g2;

    std::cout << "Differenza g - g2:\n";

    for (const auto& e : diff.all_edges())
        std::cout << e << "\n";

    return 0;
}