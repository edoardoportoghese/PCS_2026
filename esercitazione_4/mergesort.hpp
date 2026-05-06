#include <vector>
#include "merge.hpp"

template <typename T>
void mergeSort(std::vector<T>& vec, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(vec, p, q);
        mergeSort(vec, q + 1, r);
        merge(vec, p, q, r);
    }
}