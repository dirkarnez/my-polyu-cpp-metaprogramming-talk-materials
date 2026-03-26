#include <iostream>

// 1. Recursive template to calculate factorial at compile-time (C++11 style)
template<unsigned long N>
struct Factorial {
    static const unsigned long value = N * Factorial<N - 1>::value;
};

// Base case specialization
template<>
struct Factorial<0> {
    static const unsigned long value = 1;
};

// 2. The Lookup Table (LUT) Wrapper
// We use a raw array because C++11 std::array has limited constexpr support
template<unsigned long... Values>
struct FactorialTable {
    static const unsigned long data[sizeof...(Values)];
};

// Initialize the static array member
template<unsigned long... Values>
const unsigned long FactorialTable<Values...>::data[sizeof...(Values)] = { Values... };

// 3. Helper to define the specific table for 0-10
typedef FactorialTable<
    Factorial<0>::value, Factorial<1>::value, Factorial<2>::value, Factorial<3>::value, Factorial<4>::value, Factorial<5>::value,
    Factorial<6>::value, Factorial<7>::value, Factorial<8>::value, Factorial<9>::value, Factorial<10>::value
> MyTable;

int main() {
    // Accessing the table at runtime
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "! = " << MyTable::data[i] << std::endl;
    }

    // COMPILE-TIME CHECKS (static_assert)
    // In C++11, you must check the template directly, 
    // because array indexing (MyTable::data[5]) is not constexpr in C++11.
    static_assert(Factorial<5>::value == 120, "Calculation error!");
    static_assert(Factorial<10>::value == 3628800, "Calculation error!");

    return 0;
}
