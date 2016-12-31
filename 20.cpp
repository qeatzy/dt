#include "utility.h"
#include "Int.cpp"
// Factorial digit sum
// https://projecteuler.net/problem=20
// Find the sum of the digits in the number 100!

Int factorial(int n) {
    Int res{1};
    while (n>1) {
        res *= n;
        --n;
    }
    return res;
}

int main() {
    auto x = factorial(100);
    // cout << x;
    std::stringstream ss;
    ss << x;
    string s;
    ss >> s;
    // cout << s;
    auto sum_digits = [](const string& num) {
        int sum = 0;
        for (auto c: num) {
            sum += c - '0';
        }
        return sum;
    };
    cout << sum_digits(s);
}
