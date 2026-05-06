
#include <vector>
#include <utility> 

template <typename T>
int partition(std::vector<T>& vec, int p, int r) {
    T x = vec[r];      
    int i = p - 1;

    for (int j = p; j <= r - 1; ++j) {
        if (vec[j] <= x) {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[r]);
    return i + 1;
}