#include <iostream>
#include <vector>

#include "randfiller.h"
#include "insertion_sort.hpp"
#include "is_sorted.hpp"
#include <string>



int main() {
    randfiller rf;

    const int N_TEST = 100;
    const int SIZE = 100;

    for (int i = 0; i < N_TEST;i++ ) {

        std::vector<int> base(SIZE);
        rf.fill(base, 1, 1000);

 
        std::vector<int> v = base;

		insertion_sort(v);

        if (!is_sorted(v)) {
            std::cout << "Errore nel test Insertion sort " << "\n";
        }

    }
	std::vector<std::string> v_s = {
    "mela", "banana", "kiwi", "arancia", "pera",
    "uva", "ciliegia", "pesca", "limone", "fragola"
    };

    insertion_sort(v_s);
	

	if (!is_sorted(v_s)) {
    std::cout << "Errore I-S!\n";
    }
    return 0;

}