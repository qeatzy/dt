#include "utility.h"
#include "Int.cpp"

int index_of_fibnum_contains_at_least_n_digits(int n) {
    Int prev = 0, curr = 1; // 0th and 1st fib num
    int index = 1;
    while (curr.ndigits() < n) {
        auto tmp = curr + prev;
        prev = curr;
        curr = tmp;
        ++index;
    }
    return index;
}

int main() {
    int n = 1000;
    auto res = index_of_fibnum_contains_at_least_n_digits(n);
    cout << res;
}
