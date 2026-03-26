#include <iostream>
#include <array>
#include <cstdint>

// 1. A 'consteval' function MUST be evaluated at compile-time.
// This is much simpler than C++11 template recursion.
consteval uint64_t calculate_factorial(uint64_t n) {
    uint64_t res = 1;
    for (uint64_t i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

// 2. A 'consteval' generator that creates the entire array.
template <std::size_t N>
consteval auto make_factorial_lut() {
    std::array<uint64_t, N> lut{};
    for (std::size_t i = 0; i < N; ++i) {
        lut[i] = calculate_factorial(i);
    }
    return lut;
}

int main() {
    // 3. This is baked into the binary at compile-time.
    // The compiler calls make_factorial_lut<11>() and stores the result.
    static constexpr auto factorials = make_factorial_lut<11>();

    // Since it's C++20, std::array::operator[] is fully constexpr.
    // We can use it in static_assert directly!
    static_assert(factorials[5] == 120, "Works at compile-time!");
    static_assert(factorials[10] == 3'628'800, "Works at compile-time!");

    // Print values at runtime
    for (size_t i = 0; i < factorials.size(); ++i) {
        std::cout << i << "! = " << factorials[i] << "\n";
    }

    return 0;
}

