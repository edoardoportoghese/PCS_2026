#include <vector>
#include "partition.hpp"
#include "insertion_sort.hpp"

template <typename T>
void quickmix(std::vector<T>& vec, int p, int r)
{
    if (p < r)
    {
 
        if (r - p + 1 < 20)
        {
            std::vector<T> temp(vec.begin() + p, vec.begin() + r + 1);

            insertion_sort(temp);

            for (int i = 0; i < temp.size(); i++)
                vec[p + i] = temp[i];
			
			return;
        }

        int q = partition(vec, p, r);

        quickmix(vec, p, q - 1);
        quickmix(vec, q + 1, r);
    }
}