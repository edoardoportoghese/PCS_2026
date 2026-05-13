#include <stack>

using namespace std;

template <typename T>
struct Stack {

    std::stack<T> s;

    void put(T x) {
        s.push(x);
    }

    T get() {
        T v = s.top();
        s.pop();
        return v;
    }

    bool empty() {
        return s.empty();
    }
};