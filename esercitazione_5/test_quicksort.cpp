#include <iostream>
#include <vector>

#include "randfiller.h"
#include "quicksort.hpp"
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

		quicksort(v, 0, v.size()-1);

        if (!is_sorted(v)) {
            std::cout << "Errore nel test Quicksort " << "\n";
        }

    }
	std::vector<std::string> v_s = {
    "mela", "banana", "kiwi", "arancia", "pera",
    "uva", "ciliegia", "pesca", "limone", "fragola"
    };

    quicksort(v_s, 0, v_s.size()-1);
	

	if (!is_sorted(v_s)) {
    std::cout << "Errore QS-S!\n";
    }
	return 0;

}