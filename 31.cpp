#include "utility.h"
// Coin sums
// https://projecteuler.net/problem=31
// In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation: 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
// How many different ways can £2 be made using any number of coins?
// 73682

int cal_way_of_sum(int sum, std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (last - first == 1) {
        return sum % *first == 0;
    } else {
        int cnt = 0;
        int left = 0;
        for (; left <= sum; left += *first) {
            cnt += cal_way_of_sum(sum - left, first + 1, last);
        }
        return cnt;
    }
}

int cal_way_of_sum(int sum, std::vector<int> nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return cal_way_of_sum(sum, nums.begin(), nums.end());
}

int main() {
    int sum = 200;
    std::vector<int> nums{1,2,5,10,20,50,100,200};
    int res = cal_way_of_sum(sum, nums);
    cout << res;
}
