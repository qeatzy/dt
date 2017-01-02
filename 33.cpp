#include "utility.h"
// Digit cancelling fractions
// https://projecteuler.net/problem=33
// There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
// If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

int isOk(int a, int b, int c) {
    std::vector<int> vec1 {a * 10 + b, b * 10 + a};
    std::vector<int> vec2 {c * 10 + b, b * 10 + c};
    for (auto x: vec1) {
        for (auto y: vec2) {
            if (x < y && x * c == y * a) {
                cout << x << "/" << y << " = " << a << "/" << c << endl;
            }
        }
    }
    return -1;
}

int main() {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            // if (i == j) { continue; }
            for (int k = 1; k < 10; ++k) {
                // if (k == i || k == j) { continue; }
                isOk(i,j,k);
            }
        }
    }
}
