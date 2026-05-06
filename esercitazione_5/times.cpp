#include <iostream>
#include <vector>
#include <algorithm>

#include "timecounter.h"
#include "randfiller.h"
#include "bubblesort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "is_sorted.hpp"

int main() {

    randfiller rf;

    for (int n = 4; n <= 8192; n *= 2) {

        std::vector<int> base(n);
        rf.fill(base, 1, 10000);

        // copie
        auto v1 = base;
        auto v2 = base;
        auto v3 = base;
        auto v4 = base;
		auto v5 = base;
        auto v6 = base;

        timecounter tc;

        tc.tic();
        bubblesort(v1);
        double t1 = tc.toc();

        tc.tic();
        insertion_sort(v2);
        double t2 = tc.toc();

        tc.tic();
        selection_sort(v3);
        double t3 = tc.toc();

        tc.tic();
        std::sort(v4.begin(), v4.end());
        double t4 = tc.toc();
		
		tc.tic();
        quicksort(v5, 0, v5.size() - 1);
        double t5 = tc.toc();

        tc.tic();
        mergeSort(v6, 0, v6.size() - 1);
        double t6 = tc.toc();

        std::cout << n << "\t"
                  << t1 << "\t"
                  << t2 << "\t"
                  << t3 << "\t"
                  << t4 << "\t"
				  << t5 << "\t"
                  << t6 << "\n";
    }
}