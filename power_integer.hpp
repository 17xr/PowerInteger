#ifndef POWER_INTEGER_HPP
#define POWER_INTEGER_HPP

#include <gmpxx.h>
#include <iostream>
#include <optional>
#include <string>

inline std::optional<std::string> pow_int(int base, int exponent) {
    if (exponent < 0) {
        std::cerr << "pow_int(): negative exponent is not supported.\n";
        return std::nullopt;
    }

    if (base == 0) {
        if (exponent == 0) {
            std::cerr << "pow_int(): 0 ^ 0 is undefined.\n";
            return std::nullopt;
        } else {
            return "0";
        }
    }

    bool negative{};

    if (base < 0) {
        base *= -1;
        negative = (exponent % 2 != 0);
    }

    mpz_class int_result{1};

    for (int i = 0; i < exponent; ++i) {
        int_result *= base;
    }

    if (negative) {
        int_result *= -1;
    }

    std::string str_result{int_result.get_str()};

    return str_result;
}

#endif
