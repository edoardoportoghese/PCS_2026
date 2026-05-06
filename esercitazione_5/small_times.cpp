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
#include "quick_misto_insertion.hpp"

int main() {

    randfiller rf;
    const int REP = 100;

    for (int n = 5; n <= 100; n += 5) {

        double t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7=0;

        std::vector<std::vector<int>> base(REP, std::vector<int>(n));

        for (int i = 0; i < REP; i++) {
            rf.fill(base[i], 1, 1000);
        }

        timecounter tc;

        // BUBBLE
        tc.tic();
        for (int i = 0; i < REP; i++) {
            auto v = base[i];
            bubblesort(v);
        }
        t1 = tc.toc() / REP;

        // INSERTION
        tc.tic();
        for (int i = 0; i < REP; i++) {
            auto v = base[i];
            insertion_sort(v);
        }
        t2 = tc.toc() / REP;

        // SELECTION
        tc.tic();
        for (int i = 0; i < REP; i++) {
            auto v = base[i];
            selection_sort(v);
        }
        t3 = tc.toc() / REP;

        // STD SORT
        tc.tic();
        for (int i = 0; i < REP; i++) {
            auto v = base[i];
            std::sort(v.begin(), v.end());
        }
        t4 = tc.toc() / REP;

        // QUICK
        tc.tic();
        for (int i = 0; i < REP; i++) {
            auto v = base[i];
            quicksort(v, 0, v.size() - 1);
        }
        t5 = tc.toc() / REP;

        // MERGE
        tc.tic();
        for (int i = 0; i < REP; i++) {
            auto v = base[i];
            mergeSort(v, 0, v.size() - 1);
        }
        t6 = tc.toc() / REP;
		
		// QUICKMIX
        tc.tic();
        for (int i = 0; i < REP; i++) {
            auto v = base[i];
            quickmix(v, 0, v.size() - 1);
        }
        t7 = tc.toc() / REP;

        std::cout << n << "\t"
                  << t1 << "\t"
                  << t2 << "\t"
                  << t3 << "\t"
                  << t4 << "\t"
                  << t5 << "\t"
                  << t6 << "\t"
				  << t7 << "\n";
    }

    return 0;
}