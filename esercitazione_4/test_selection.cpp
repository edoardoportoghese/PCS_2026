#include <iostream>
#include <vector>

#include "randfiller.h"
#include "selection_sort.hpp"
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

		selection_sort(v);

        if (!is_sorted(v)) {
            std::cout << "Errore nel test Selection sort " << "\n";
        }

    }
	std::vector<std::string> v_s = {
    "mela", "banana", "kiwi", "arancia", "pera",
    "uva", "ciliegia", "pesca", "limone", "fragola"
    };

    selection_sort(v_s);
	

	if (!is_sorted(v_s)) {
    std::cout << "Errore S-S!\n";
    }
	return 0;

}