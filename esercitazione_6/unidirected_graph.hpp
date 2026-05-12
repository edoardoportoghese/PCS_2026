#include <set>
#include <vector>
#include <iterator>

#include "unidirected_edge.hpp"

template<typename T>
class unidirected_graph {

private:

    // insieme di tutti i nodi del grafo
    std::set<T> nodes;

    // insieme di tutti gli archi del grafo
    std::set<unidirected_edge<T>> edges;

public:

    // costruttore di default
    unidirected_graph() = default;

    // costruttore di copia
    unidirected_graph(const unidirected_graph& other)
        : nodes(other.nodes),
          edges(other.edges) {}

    // aggiunge un arco al grafo
    void add_edge(const unidirected_edge<T>& e) {

        // inserisce l'arco
        edges.insert(e);

        // aggiunge automaticamente anche i nodi
        nodes.insert(e.from());
        nodes.insert(e.to());
    }

    // restituisce tutti i nodi del grafo
    std::set<T> all_nodes() const {
        return nodes;
    }

    // restituisce tutti gli archi del grafo
    std::vector<unidirected_edge<T>> all_edges() const {

        return std::vector<unidirected_edge<T>>(
            edges.begin(),
            edges.end()
        );
    }

    // restituisce i vicini di un nodo
    std::set<T> neighbours(const T& node) const {

        std::set<T> result;

        // scorre tutti gli archi
        for (const auto& e : edges) {

            // se il nodo è from
            // aggiunge to
            if (e.from() == node)
                result.insert(e.to());

            // se il nodo è to
            // aggiunge from
            else if (e.to() == node)
                result.insert(e.from());
        }

        return result;
    }

    // restituisce il numero/indice di un arco
    int edge_number(const unidirected_edge<T>& edge) const {

        int index = 0;

        // scorre tutti gli archi
        for (const auto& e : edges) {

            // arco trovato
            if (e == edge)
                return index;

            index++;
        }

        // arco non trovato
        return -1;
    }

    // restituisce l'arco alla posizione index
    unidirected_edge<T> edge_at(int index) const {

        auto it = edges.begin();

        // sposta l'iteratore in avanti
        std::advance(it, index);

        return *it;
    }

    // differenza tra due grafi
    // restituisce gli archi presenti
    // in questo grafo ma non nell'altro
    unidirected_graph operator-(const unidirected_graph& other) const {

        unidirected_graph result;

        // scorre tutti gli archi
        for (const auto& e : edges) {

            // se l'arco non esiste nell'altro grafo
            if (other.edges.find(e) == other.edges.end())
                result.add_edge(e);
        }

        return result;
    };
};