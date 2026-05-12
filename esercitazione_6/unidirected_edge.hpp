#include <iostream>

template<typename T>
class unidirected_edge {
private:
    T m_from;
    T m_to;

public:
    unidirected_edge(T a, T b) {
        if (a <= b) {
            m_from = a;
            m_to = b;
        } else {
            m_from = b;
            m_to = a;
        }
    }

    T from() const {
        return m_from;
    }

    T to() const {
        return m_to;
    }

    bool operator<(const unidirected_edge& other) const {
        if (m_from != other.m_from)
            return m_from < other.m_from;

        return m_to < other.m_to;
    }

    bool operator==(const unidirected_edge& other) const {
        return m_from == other.m_from &&
               m_to == other.m_to;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os,
                         const unidirected_edge<T>& e) {
    os << "(" << e.from() << ", "
       << e.to() << ")";

    return os;
}