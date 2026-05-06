#include <vector>
#include "partition.hpp"


template <typename T>
void quicksort(std::vector<T>& vec, int p, int r) {
    if (p < r) {
        int q = partition(vec, p, r);  
        quicksort(vec, p, q - 1);
        quicksort(vec, q + 1, r);
    }
}