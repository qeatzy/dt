// largest prime factor of 600851475143 . https://projecteuler.net/problem=3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

typedef std::vector<int> iVec;
typedef std::vector<long long> llVec;

using std::cout;

bool is_prime(long long val) {
    long long ulimit = sqrt(val);
    for(long long i=2; i<ulimit; ++i) {
        if (val % i == 0)
            return false;
    }
    return true;
}

long long smallest_factor_and_larger_than(long long val, long long pre_start) {
    long long ulimit = sqrt(val);
    while(++pre_start <= ulimit) {
        if (val % pre_start == 0)
            return pre_start;
    }
    return val;
}
    

long long largest_prime_factor(long long val) {
    llVec factors;
    long long factor = 1;
    while(true) {
        factor = smallest_factor_and_larger_than(val, factor);
        factors.push_back(factor);
        if (factor == val)
            break;
    }
    long long res = 1;
    for(auto x: factors) {
        if(is_prime(x))
            res = x;
    }
    return res;
}

int main() {
    long long threshold = 600851475143;
    cout << largest_prime_factor(threshold);
}
