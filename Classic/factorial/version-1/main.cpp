#include <iostream>

// Precompute values using nested ternary operators
#define FACTORIAL(n) ( \
    (n) == 0 ? 1 :     \
    (n) == 1 ? 1 :     \
    (n) == 2 ? 2 :     \
    (n) == 3 ? 6 :     \
    (n) == 4 ? 24 :    \
    (n) == 5 ? 120 :   \
    (n) == 6 ? 720 :   \
    (n) == 7 ? 5040 :  \
    (n) == 8 ? 40320 : \
    (n) == 9 ? 362880 : 3628800)

int main() {
    std::cout << "5! is " << FACTORIAL(5) << std::endl;
    return 0;
}
