#include <queue>

template <typename T>
struct Queue {

    std::queue<T> q;

    void put(T x) {
        q.push(x);
    }

    T get() {
        T v = q.front();
        q.pop();
        return v;
    }

    bool empty() {
        return q.empty();
    }
};
