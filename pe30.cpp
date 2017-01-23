#include "utility.h"
// Digit fifth powers
// https://projecteuler.net/problem=30
// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
// 443839

std::vector<int> all_num_sum_of_k_th_power_of_own_digits(int k) {
    assert (k < 10);
    std::array<int, 10> ptable{};
    for (int i = 1; i < 10; ++i) {
        ptable[i] = std::pow(i,k);
    }
    std::vector<int> res;
    for (int i = 2, ulimit = ptable[9] * (k+1); i < ulimit; ++i) {
        int sum_of_digits = 0;
        for (int j = i; j > 0; j /= 10) {
            sum_of_digits += ptable[j%10];
        }
        if (i == sum_of_digits) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    std::vector<int> res = all_num_sum_of_k_th_power_of_own_digits(4);
    print(res);
    cout << std::accumulate(res.begin(), res.end(), 0);
}
