#include "utility.h"
// Double-base palindromes
// https://projecteuler.net/problem=36
// The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
// (Please note that the palindromic number, in either base, may not include leading zeros.)
// 872187

bool palindrome_in_decimal_and_binary(int n) {
    std::vector<int> digits;
    for (auto x = n; x > 0; x /= 10) {
        digits.push_back(x % 10);
    }
    if (std::equal(digits.begin(), digits.end(), digits.rbegin())) {
        digits.clear();
        for (auto x = n; x > 0; x /= 2) {
            digits.push_back(x % 2);
        }
        return std::equal(digits.begin(), digits.end(), digits.rbegin());
    }
    return false;
}

// void print(const std::iterator<int> p, int n) {
//     for (auto i = 0; i < n; ++i) printf("%9d, ", p[i]); putchar('\n');
// }

bool palindrome_in_decimal_and_binary2(int n) {
    std::array<int, 32> digits;
    int sz = 0;
    for (int x = n; x > 0; x /= 10) {
        digits[sz++] = x %10;
    }
    if (std::equal(digits.begin(), digits.begin() + sz, digits.rbegin() + (digits.size() - sz))) {
        int sz = 0;
        for (auto x = n; x > 0; x /= 2) {
            digits[sz++] = x % 2;
        }
        return std::equal(digits.begin(), digits.begin() + sz, digits.rbegin() + (digits.size() - sz));
    }
    return false;
}

int main() {
    std::vector<int> res;
    for (int i = 1; i < 1e6; ++i) {
    // for (auto i: {585}) {
        // if (palindrome_in_decimal_and_binary(i)) {
        if (palindrome_in_decimal_and_binary2(i)) {
            res.push_back(i);
        }
    }
    print(res);
    cout << "sum = " << std::accumulate(res.begin(), res.end(), 0);
}
