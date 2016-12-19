// smallest positive number that is evenly divisible by all of the numbers from 1 to 20?  https://projecteuler.net/problem=5
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <valarray>
#include "utility.h"

class Prime;

long long smallest_number_divisible_by_all_number_upto(int threshold) {
    Prime p;
    auto primes = p(threshold);
    print(primes);
    auto raise_to_lagest_power_upto = [threshold](int x) {
        auto res = x;
        while (res * x <= threshold)
            res *= x;
        return res;
    };
    std::transform(primes.begin(), primes.end(), primes.begin(), raise_to_lagest_power_upto);
    print(primes);
    return std::accumulate(primes.begin(), primes.end(), 1, [](int x, int y) { return x*y; });
}

int main() {
    // auto nums = range(6);
    // print(nums);
    // cout << *std::lower_bound(nums.begin(), nums.end(), 3);
    // cout << *std::upper_bound(nums.begin(), nums.end(), 3);

    // std::valarray<int> orig = { 0,1,2,3,4,5,6,7,8,9 };
    // std::valarray<size_t> index = { 3,5,6,8 };
   // orig[index] = -1;
   // for (int i=0; i<orig.size(); i++)
    //     std::cout << orig[i] << "\t";

    int threshold = 20;
    cout << smallest_number_divisible_by_all_number_upto(threshold);
    // Prime p;
    // print(p(10));
    // print(p(20));
    // print(p(100));
}
