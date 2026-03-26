#include <iostream>
#include <array>
#include <cstdint>

/**
 * @brief Factorial Lookup Table Template
 * @tparam N The number of elements to store (0 through N-1)
 */
template <std::size_t N>
struct FactorialLUT {
    std::array<uint64_t, N> values;

    constexpr FactorialLUT() : values{} {
        values[0] = 1; // 0! = 1
        for (std::size_t i = 1; i < N; ++i) {
            values[i] = values[i - 1] * i;
        }
    }

    // Accessor
    constexpr uint64_t get(std::size_t n) const {
        return values[n];
    }
};

int main() {
    // Generate the table for 0 through 10 at compile-time
    // We use 11 as the size to include the index 10
    static constexpr auto factorials = FactorialLUT<11>();

    // Test output
    std::cout << "Factorial Lookup Table (0-10):" << std::endl;
    for (std::size_t i = 0; i < factorials.values.size(); ++i) {
        std::cout << i << "! = " << factorials.get(i) << std::endl;
    }

    // Example of direct access
    static_assert(factorials.get(5) == 120, "Compile-time check failed!");
    
    return 0;
}
