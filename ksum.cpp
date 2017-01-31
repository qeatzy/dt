#include "utility.h"
// for even K, reduce to 2 sum for a larger list (sum of K/2). for odd K reduce to 3 sum of two list (eg, K/2 and original input). http://cs.stackexchange.com/questions/2973/generalised-3sum-k-sum-problem
// https://leetcode.com/problems/3sum/
// https://discuss.leetcode.com/topic/8125/concise-o-n-2-java-solution
// https://discuss.leetcode.com/post/74515  -- not worth to complicate the intent of your code. -- and is there indeed any performance gain?

std::vector<std::vector<int>> threeSum_old(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        if (nums.empty()) return res;
        std::vector<int> positive, negative;
        int nzero = 0;
        for (auto val: nums) {
            if (val == 0) { ++nzero; }
            else if (val < 0) { negative.push_back(-val); }
            else { positive.push_back(val); }
        }
        if (nzero >= 3) { res.push_back(std::vector<int> {0,0,0}); }
        if (negative.empty() || positive.empty()) { return res; }
        auto pseudoUniqify = [](std::vector<int> &vec) {
            std::vector<int> tmp;
            tmp.swap(vec);
            std::sort(tmp.begin(), tmp.end());
            for (auto it = tmp.begin(); it != tmp.end(); ) {
                auto val = *it;
                vec.push_back(val);
                if (++it != tmp.end() && *it == val) {
                    vec.push_back(val);
                    for (; ++it != tmp.end() && *it == val; ) {}
                }
            }
        };
        // print(negative);
        // print(positive);
        pseudoUniqify(negative);
        pseudoUniqify(positive);
        // print(negative);
        // print(positive);
        // wait();
        typedef decltype(negative.begin()) It;
        auto findAndAppend = [](std::vector<std::vector<int>> &dest, It lfirst, It llast, It rfirst, It rlast, int shift, bool twonega) {
            assert(rfirst < rlast);
            // cout << "twonega = " << twonega << ", shift = " << shift << endl;
            // print(lfirst, llast);
            // print(rfirst, rlast);
            // wait();
            decltype(shift) max = rlast[-1];
            if (max < *lfirst + shift) return rlast;
            // cout << "max = " << max << endl;
            for (; *rfirst < *lfirst + shift; ++rfirst) {}
            auto res = rfirst;
            for (; lfirst != llast && *lfirst + shift < max; ) {
                auto sum = *lfirst + shift;
                // cout << "sum = " << sum << endl;
                // wait();
                for (; *rfirst < sum; ++rfirst) {}
                if (*rfirst == sum) {
                    if (twonega) dest.push_back(std::vector<int> {-*lfirst, -shift, *rfirst});
                    else dest.push_back(std::vector<int> {shift, *lfirst, -*rfirst});
                }
                if (++lfirst != llast && lfirst[-1] == lfirst[0]) { ++lfirst; }
            }
            if (lfirst != llast && *lfirst + shift == max) {
                if (twonega) dest.push_back(std::vector<int> {-*lfirst, -shift, max});
                else dest.push_back(std::vector<int> {shift, *lfirst, -max});
            }
            return res;
        };
        if (nzero > 0) { findAndAppend(res, negative.begin(), negative.end(), positive.begin(), positive.end(), 0, true); }
        for (auto it = negative.begin(), it_end = negative.end(), rit = positive.begin(), rit_end = positive.end(); it < it_end && rit < rit_end; ) {
            auto val = *it;
            ++it;
            if (it == it_end) break;
            rit = findAndAppend(res, it, it_end, rit, rit_end, val, true);
            if (*it == val) { ++it; }
        }
        for (auto it = positive.begin(), it_end = positive.end(), rit = negative.begin(), rit_end = negative.end(); it < it_end && rit < rit_end; ) {
            auto val = *it;
            // cout << "*it = " << *it << ", val = " << val << endl;
            // wait();
            ++it;
            if (it == it_end) break;
            rit = findAndAppend(res, it, it_end, rit, rit_end, val, false);
            if (*it == val) { ++it; }
        }
        // std::sort(res.begin(), res.end());
        return res;
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        if (nums.empty() || nums[0] >= 0 || nums.back() <= 0) {
            auto sz = nums.size();
            if (sz >= 3) {
                if ((nums[0] == 0 && nums[2] == 0) || (nums[sz-1] == 0 && nums[sz-3] == 0)) { res.push_back({0,0,0}); }
            }
        } else for (size_t i = 0; nums[i] <= 0; ) {
            auto val = nums[i];
            for (size_t low = i + 1, high = nums.size() - 1; low < high; ) {
                auto sum = val + nums[low] + nums[high];
                if (sum == 0) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    for (auto val_low = nums[low]; ++low < high && nums[low] == val_low; ) {}
                    for (auto val_high = nums[high]; --high > low && nums[high] == val_high; ) {}
                } else if (sum < 0) { ++low; }
                else { --high; }
            }
            for (; ++i < nums.size() && nums[i] == val; ) {}
        }
        return res;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    for (int a = 0, a_end = nums.size() - 3; a < a_end; ) {
        if (a == 0 || nums[a] != nums[a-1]) {
        }
    }
    return res;
}

namespace test {
    void threeSum() {
        auto test_case = []() {
            std::vector<std::vector<int>> res;
            // res.push_back({-1, 0, 1, 2, -1, -4});
            res.push_back({-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6});
            // res.push_back({});
            // res.push_back({1,2,-2,-1});
            // res.push_back({-1,0,1,2,-1,-4});
            // res.push_back({3,-2,1,0});
            // res.push_back({1,1,-2});
            return res;
        };
        for (auto v: test_case()) {
            print(v);
            auto res = ::threeSum(v);
            // auto res = ::threeSum_old(v);
            print(res);
        }
    }
}

int main() {
    test::threeSum();
}
