#include <vector>
#include <limits>

template <typename T>
void merge(std::vector<T>& vec, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<T> L(n1 + 1);
    std::vector<T> R(n2 + 1);

    for (int i = 0; i < n1; ++i) {
        L[i] = vec[p + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = vec[q + 1 + j];
    }


    L[n1] = std::numeric_limits<T>::max();
    R[n2] = std::numeric_limits<T>::max();

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            ++i;
        } else {
            vec[k] = R[j];
            ++j;
        }
    }
}