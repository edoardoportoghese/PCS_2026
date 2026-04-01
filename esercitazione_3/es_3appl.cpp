#include <iostream>
#include "es_3.hpp"

int main() {
    // Creo due razionali normali
    rational<int> a(2,-5);  
    rational<int> b(1, 2);

    // Riduzione ai minimi termini
    a.simplify();
    b.simplify();

    std::cout << "a = " << a.num() << "/" << a.den() << "\n";
    std::cout << "b = " << b.num() << "/" << b.den() << "\n\n";

    // Operazioni canoniche
    auto sum = a + b;
    auto diff = a - b;
    auto prod = a * b;
    auto div = a / b;

    std::cout << "a + b = " << sum.num() << "/" << sum.den() << "\n";
    std::cout << "a - b = " << diff.num() << "/" << diff.den() << "\n";
    std::cout << "a * b = " << prod.num() << "/" << prod.den() << "\n";
    std::cout << "a / b = " << div.num() << "/" << div.den() << "\n";

    return 0;
}