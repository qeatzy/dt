#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>

typedef std::vector<int> iVec;

using std::cout;

int sum_of_multiple_of_prime_pair_below_threshold(iVec nums, int threshold) {
    /* be aware of overflow concerns!
     */
    int res = 0;
    auto sum_to = [](int n) { return (n%2)? (n+1)/2 * n : n/2 * (n+1); };
    auto find_upper_bound = [threshold](int x) { return (threshold-1) / x; };
    auto sum_multiple_until = [=](int x) { return x * sum_to(find_upper_bound(x)); };
    for(auto x: nums) {
        res += sum_multiple_until(x);
    }
    res -= sum_multiple_until(nums[0] *nums[1]);
    return res;
}

int main() {
    iVec nums {3,5};
    int threshold = 1000;
    int res = sum_of_multiple_of_prime_pair_below_threshold(nums, threshold);
    cout << res;
}
